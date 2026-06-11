#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct p{
  long long first;
  int w;

  bool operator<(const p & right) const {
    return first == right.first ? w < right.w : first < right.first;
  }
};

int main(){
  long long n, l, t; cin >> n >> l >> t;
  vector< p > x(n);
  for(int i = 0 ; i < n; i++){
    cin >> x[i].first >> x[i].w;
  }
  long long stand = 0;
  for(long long i = 0 ; i < n ; i++){
    if(x[i].w == 1){
      stand += (x[i].first + t) / l;
      x[i].first = (x[i].first + t)%l;
    }
    else if(x[i].w == 2){
      stand -= (l - x[i].first  + t - 1) / l;
      x[i].first = (x[i].first + l - t%l) % l;
    }
  }
  sort(x.begin(), x.end());
  //for(long long i = 0 ; i < n ; i++) cout << stand << x[i].first << endl;
  for(long long i = 0 ; i < n ; i++){
    if(stand >= 0) cout << x[(i + stand%n)%n].first << endl;
    if(stand < 0)cout << x[(i + n - (-1*stand)%n) % n].first << endl;
  }
}
