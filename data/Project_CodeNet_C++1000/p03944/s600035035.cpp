#include <iostream>
#include <vector>
using namespace std;

int main(){
  int W, H, N;
  cin >> W >> H >> N;
  vector<int> x(N), y(N), a(N);
  for(int i=0; i<N; i++){
    cin >> x.at(i) >> y.at(i) >> a.at(i);
  }
  int x_white_first=0, x_white_last=W;
  int y_white_first=0, y_white_last=H;
  for(int i=0; i<N; i++){
    switch(a.at(i)){
      case 1:
        x_white_first=max(x_white_first,x.at(i));
        break;
      case 2:
        x_white_last=min(x_white_last,x.at(i));
        break;
      case 3:
        y_white_first=max(y_white_first,y.at(i));
        break;
      case 4:
        y_white_last=min(y_white_last,y.at(i));
    }
  }
  int xlength=max(0,x_white_last-x_white_first);
  int ylength=max(0,y_white_last-y_white_first);
  cout << xlength*ylength;
  return 0;
}