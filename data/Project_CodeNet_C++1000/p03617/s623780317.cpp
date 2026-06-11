#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
 
int main(){
  ll q,h,s,d,n;
  cin >> q >>h >> s >> d >> n;
  ll H;
  H=min(q*2,h);
  ll S;
  S=min(H*2,s);
  if(S*2<=d) cout << n*S << endl;
  else{
    if(n%2==0){
      cout << (n/2)*d << endl;
    }
    else{
      cout << (n/2)*d+S << endl;
    }
  }
        
}