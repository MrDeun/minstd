#pragma once

#include <stdlib.h>

namespace minstd {
template <typename T> class vector {
private:
  using ConstFunc = void (*)(const T &);
  using Func = void (*)(T &);
  // using MapFunc = std::function<void(T &)>;
  T *m_data = nullptr;
  size_t m_size = 0;
  size_t m_capacity = 16;

  vector() { m_data = malloc(m_capacity * sizeof(T)); }
  ~vector() {
    if (m_data) {
      free(m_data);
      m_data = nullptr;
    }
  }

  T &operator[](size_t i) const {
    if (i > 0 && i < m_size) {
      return m_data[i];
    }
  }

  size_t size() const { return m_size; }
  size_t capacity() const { return m_capacity; }

  void for_each(ConstFunc func) {
    for (size_t i = 0; i < m_size; i++) {
      func(m_data[i]);
    }
  };

  void resize(size_t new_size) { m_size = new_size; }
  void realloc(size_t new_capacity) {
    m_data = realloc(m_data, new_capacity * sizeof(T));
    m_capacity = new_capacity;
  }
};
}; // namespace minstd