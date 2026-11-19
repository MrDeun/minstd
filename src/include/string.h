#ifndef MINSTD_STRING_H
#define MINSTD_STRING_H
#include <cstdlib>
#include <stddef.h>
#include <stdlib.h>
namespace minstd {

class string {
  char *m_cstr = nullptr;
  size_t m_size = 0;
  size_t m_capacity = 0;

public:
  size_t size() const noexcept { return m_size; }
  size_t capacity() const noexcept { return m_capacity; }
  char *cstr() const noexcept { return m_cstr; }
  void clean_up() noexcept {
    free(m_cstr);
    m_size = 0;
    m_capacity = 0;
  }

  string() {}
  ~string() { free(m_cstr); }
  string(const string &other)
      : m_size(other.size()), m_capacity(other.capacity()) {
    m_cstr = (char *)malloc(sizeof(char) * m_capacity);
  };
  string &operator=(const string &other) {
    if (m_cstr) {
      m_cstr = (char *)realloc(m_cstr, sizeof(char) * other.capacity());
    } else {
      m_cstr = (char *)malloc(sizeof(char) * other.capacity());
    }

    m_capacity = other.capacity();
    m_size = other.size();

    return *this;
  }

  string inherit(string &other) {
    m_cstr = other.cstr();
    m_size = other.size();
    m_capacity = other.capacity();

    other.clean_up();
    return *this;
  }
};

}; // namespace minstd
#endif