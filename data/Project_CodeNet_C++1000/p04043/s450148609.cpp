#include <iostream>

int main() {
  int v[3];
  for( size_t i = 0; i < 3; ++i ) {
    scanf("%d", &v[i]);
  }

  std::sort(v, v+3);
  const bool ok = (
    v[0] == 5 &&
    v[1] == 5 &&
    v[2] == 7
  );
  if( ok ) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
}