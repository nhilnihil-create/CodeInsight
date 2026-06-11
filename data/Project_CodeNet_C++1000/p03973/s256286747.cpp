#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  long long n,ans=0;
  cin >> n;
  int a;
  cin >> a;
  ans=ans+a-1;
  long long ma=1;
  rep(i,n-1){
    int p;
    cin >> p;
    if(p==ma+1){
      ma++;
      continue;
    }
    ans+=(p-1)/(ma+1);
  
  }
  cout << ans << endl;
}
