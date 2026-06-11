#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#include <vector>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> k(n, 0);
  rep(i,n){
    cin >> a[i];
    if(a[i] % 4 == 0){
      k[i] = 2;
    }else if(a[i] % 2 == 0){
      k[i] = 1;
    }
  }
  int cnt = 0;
  int t = 0;
  rep(i,n){
    if(!k[i]) cnt++;
    if(k[i]==1) t++;;
  }
  cnt = (t > 0) ? cnt+1 : cnt;
  n -= max(t - 1, 0);
  if(n%2==0 && cnt > n/2){
    cout << "No" << endl;
    return 0;
  }else if(n%2==1 && cnt > (int)n/2+1){
    cout << "No" << endl;
    return 0;
  }else{
    cout << "Yes" << endl;
  }
  return 0;
}