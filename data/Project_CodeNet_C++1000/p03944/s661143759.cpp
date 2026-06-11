#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<string>
#include<queue>
#include<utility>
#include<cmath>
#include<sstream>
#include<istream>
#include<numeric>
#include<stdlib.h>

using namespace std;

int main()
{

  int W, H, N;
  cin >> W >> H >> N;

  vector<int> x(N);
  vector<int> y(N);
  vector<int> a(N);

  for(int i=0; i<N; i++){
    cin >> x[i] >> y[i] >> a[i];
  }

  int x_min = 0;
  int x_max = W;
  int y_min = 0;
  int y_max = H;

  for(int i=0; i<N; i++){
    if(a[i] == 1){
      x_min = max(x_min,x[i]);
    }
    if(a[i] == 2){
      x_max = min(x_max,x[i]);
    }
    if(a[i] == 3){
      y_min = max(y_min,y[i]);
    }
    if(a[i] == 4){
      y_max = min(y_max,y[i]);
    }
  }

  if((y_max-y_min) < 0 || (x_max-x_min) < 0){
    cout << 0 << endl;
  }
  else{
    cout << (y_max-y_min)*(x_max-x_min) << endl;
  }

  return 0;
}
