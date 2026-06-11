#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

#define int long long

int n, a, b;
int h[100000];

bool enough(int t)
{
  ll sum = 0;
  for(int i = 0; i < n; i++){
    if(t*b < h[i])
      sum += (h[i]-b*t+a-b-1) / (a-b);
  }
  return sum <= t;
}

signed main()
{
  cin >> n >> a >> b;

  for(int i = 0; i < n; i++){
    cin >> h[i];
  }

  int l = 0, r = 1e+9;
  while(l + 1 < r){
    int m = (l+r)/2;
    if(enough(m)){
      r = m; 
    }else{
      l = m;
    }
  }

  cout << r << endl;

  return 0;
}
