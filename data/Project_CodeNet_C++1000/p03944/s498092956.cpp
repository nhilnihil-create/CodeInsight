#include<iostream>

using namespace std;

int main(){
  int W, H, N;
  cin >> W >> H >> N;
  int left = 0;
  int right = W;
  int bottom = 0;
  int top = H;
  for(int i=0; i<N; i++){
    int x, y, a;
    cin >> x >> y >> a;
    switch(a){
      case 1:
        left = max(left, x);
		break;
      case 2:
        right = min(right, x);
		break;
      case 3:
        bottom = max(bottom, y);
		break;
      case 4:
        top = min(top, y);
		break;
    }
  }
  if(right-left<0 || top-bottom<0){
    cout << 0 << endl;
  }else{
    cout << (right-left)*(top-bottom) << endl;
  }
  return 0;
}
