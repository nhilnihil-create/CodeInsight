#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
  ll q,h,s,d;cin >>q>>h>>s>>d;
  ll n;cin >>n;n*=4;
  vector<ll>a={q*8,h*4,s*2,d};
  sort(all(a));
  ll ans=0;
  ans+=a[0]*(n/8);
//  cout <<ans <<endl;
  n%=8;
  ll now=INF;
    for (int i =0; i <=1; ++i) {
        for (int j = 0; j <=2; ++j) {
            for (int k = 0; k <=4; ++k) {
                for (int l = 0; l <=8; ++l) {
                    if(1*l+2*k+4*j+8*i!=n)continue;
                    now=min(q*l+h*k+s*j+d*i,now);
                }
            }
        }
    }
    ans+=now;
    cout <<ans <<endl;
}
