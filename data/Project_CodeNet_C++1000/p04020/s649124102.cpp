#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
  int n;
  cin >> n;
  long long p[n];
  rep(i,n){
    cin >> p[i];
  }
  long long ans=0;
  int w=0;
  int ww=0;
  rep(i,n){
    int a=i;
    int b=p[i];
    if(ww==a-1&&w==1&&b!=0){
      w=0;
      b--;
      ans++;
        
    }
    if(b%2==1){
      ww=a;
      w=1;
      ans+=b/2;
    }
    else ans+=b/2;
    //cout << ans << endl;
  }
  cout << ans << endl;
}
