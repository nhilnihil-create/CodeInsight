#include <cstdio>
#include <cstdint>
#include <algorithm>

int main() {
  intmax_t X, Y;
  scanf("%jd %jd", &X, &Y);

  if (X < Y)
    std::swap(X, Y);

  printf("%s\n", (X-Y>1)? "Alice":"Brown");
}
