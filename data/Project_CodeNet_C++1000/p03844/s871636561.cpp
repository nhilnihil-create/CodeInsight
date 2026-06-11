#include <cstdio>

using namespace std;

int main()
{
  long long a, b;
  char op;

  scanf("%lld %c %lld", &a, &op, &b);
  if (op == '+') {
    printf("%lld\n", a+b);
  } else if (op == '-') {
    printf("%lld\n", a-b);
  }
  return 0;
}
