#include <iostream>
#include <vector>

int32_t sgn(int32_t val) { return (val > 0) - (val < 0); }

int main() {
  uint32_t n = 0;
  std::cin >> n;
  std::vector<int32_t> A(n);
  for (auto&& a : A) std::cin >> a;

  const int32_t flip = -1;
  int32_t sum = 0, sign = 1;
  uint64_t op_plus = 0;
  for (size_t i = 0; i < A.size(); i++) {
    int32_t diff = (sign == sgn(sum + A[i])) ? 0 : sign - (sum + A[i]);
    op_plus += std::abs(diff);
    sum += A[i] + diff;
    sign *= flip;
  }

  sum = 0;
  sign = -1;
  uint64_t op_minus = 0;
  for (size_t i = 0; i < A.size(); i++) {
    int32_t diff = (sign == sgn(sum + A[i])) ? 0 : sign - (sum + A[i]);
    op_minus += std::abs(diff);
    sum += A[i] + diff;
    sign *= flip;
  }

  std::cout << std::min(op_plus, op_minus) << std::endl;

  return 0;
}