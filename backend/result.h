#pragma once
#include <string>

template <typename T> class Result {
public:
  Result(const T &result, bool success = true, const std::string &msg = "")
      : result(result), success(success), msg(msg) {}

  void ignore() const {}
  T &getResult() { return result; }
  bool isSuccess() { return success; }

private:
  T result;
  bool success = true;
  std::string msg = "";
};
