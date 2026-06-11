#include <iostream>
#include <cstdio>

using namespace std;
#define M 110000
int main(){
  int N, a[M], i, j, num=0;
  cin >> N;
  for (i = 0; i < N; i++)
    cin >> a[i];
  for (i = 0; i < N; i++){
    if (a[i]%2)
      num ++;
  }
  if (num%2)
    cout << "NO" << endl;
  else
    cout << "YES" << endl;
  return 0;
}
