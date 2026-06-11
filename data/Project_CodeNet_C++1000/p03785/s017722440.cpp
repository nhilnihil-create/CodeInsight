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
    ll ans=1;
    ll n,c,k;cin >>n>>c>>k;
    vector<int>t(n);
    for (int i = 0; i < n; ++i)cin >>t[i];
    sort(all(t));
    int s=t[0];
    int ride=0;
    int i=0;
    while(i<n){
        if(t[i]-s>k||ride>=c){
            ans++;
            s=t[i];
            ride=1;
            i++;
//            cout <<s<<endl;
        }
        else {
            ride++;
            i++;
        }
    }
    cout <<ans <<endl;
}
