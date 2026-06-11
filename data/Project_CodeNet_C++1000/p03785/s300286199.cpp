#include <bits/stdc++.h>
#define P pair<int, int>

using namespace std;
const int INF=1e5;

int main(){
  long long n, c, k, t[100009];
  cin >> n >> c >> k;
  for(int i=0;i<n;i++)cin >> t[i];
  long long cnt=0;
  sort(t, t+n);
  long long last=0;
  long long cc=0;
  for(int i=0;i<n;i++){
    if(last<t[i] || cc+1>c){
      cnt++;
      cc=1;
      last=t[i]+k;
    }
    else{
      cc++;
    }
  }
  cout << cnt << endl;
}

