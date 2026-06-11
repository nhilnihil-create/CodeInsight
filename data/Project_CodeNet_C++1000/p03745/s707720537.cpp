#include <bits/stdc++.h>
#define P pair<int, int>

using namespace std;
const int INF=1e5;

int main(){
  long long n, a[100009];
  cin >> n;
  for(int i=0;i<n;i++)cin >> a[i];
  long long delta=0, cnt=1;
  for(int i=1;i<n;i++){
    if(delta*(a[i]-a[i-1])<0){
      delta=0;
      cnt++;
    }
    else if(a[i]-a[i-1]!=0){
      delta=a[i]-a[i-1];
    }
  }
  cout << cnt << endl;
}

