#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int K, T;
  cin >> K >> T;
  int a[T], s = 0;
  for (int i = 0; i < T; i++){
    cin >> a[i];
    s += a[i];
  }

  sort(a, a+T);

  s -= a[T-1];

  if(s < a[T-1]){
    printf("%d\n", a[T-1] - s - 1);
  }else{
    printf("0\n");
  }
}
