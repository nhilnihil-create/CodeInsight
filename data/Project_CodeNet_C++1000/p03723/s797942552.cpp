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
    ll a,b,c;cin >>a>>b>>c;
    ll ans=0;
    while(1) {
        if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1)break;
        if(a==b&&b==c){
            ans=-1;
            break;
        }
        int na=a,nb=b,nc=c;
        a=(nb+nc)/2;
        b=(na+nc)/2;
        c=(na+nb)/2;
        ans++;
    }
    cout <<ans <<endl;
}
