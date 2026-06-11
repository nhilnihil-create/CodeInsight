#include <cstdio>
#include <cstdlib>

using ll = long long;

ll X, Y;

int main()
{
  scanf( "%lld%lld", &X, &Y );

  puts( llabs(X-Y) <= 1 ? "Brown" : "Alice" );

  return 0;
}