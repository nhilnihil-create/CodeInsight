#include<iostream>
using namespace std;

int main (){
  int W, H, N;
  cin >> W >> H >> N;
  int x[N];
  int y[N];
  int a[N];
  for (int i = 0; i < N; i ++){
    cin >> x[i] >> y[i] >> a[i];
  }
  
  int left = 0, right = W, top = H, bottom = 0;
  
  for (int i = 0; i < N; i ++){
    switch (a[i]){
      case 1:
        if (x[i] > left) {
          left = x[i];
        }
        break;
      case 2:
        if (x[i] < right) {
          right = x[i];
        }
        break;
      case 3:
        if (y[i] > bottom) {
          bottom = y[i];
        }
        break;
      case 4:
        if (y[i] < top) {
          top = y[i];
        }
        break;
    }
  }
  if (right < left || top < bottom){
    cout << 0 <<  '\n';
  } else {
    cout << (right - left) * (top - bottom) << '\n';
  }
}