#ifndef MINSTD_RESULT_H
#define MINSTD_RESULT_H
namespace minstd {
template <typename T, typename E> class result {
  union data {
    T value;
    E error;
  };

  const data m_data;
  const bool valid;

  result(T _value) : valid(true), m_data() { m_data.value = _value; }
  result(E _error) : valid(false), m_data() { m_data.error = _error; }

  const T &value() const {
    if (valid) {
      return m_data.value;
    }
    throw "Invalid operator";
  }
};

} // namespace minstd
#endif