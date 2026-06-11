#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> vec(n);
  rep(i, n) cin >> vec[i];
  int cnt = 1;
  int status = 0;
  rep(i, n-1){
    if(status == 0){
      if(vec[i+1]-vec[i] < 0) status = -1;
      else if(vec[i+1]-vec[i] > 0) status = 1;
    }else if(status == 1){
      if(vec[i+1]-vec[i] < 0){
        status = 0;
        cnt++;
      }
    }else{
      if(vec[i+1]-vec[i] > 0){
        status = 0;
        cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
  
