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
    ll n;cin >>n;
    vector<ll>a(n);
    set<string>s;
    ll free=0;
    for (int i = 0; i < n; ++i) {
        cin >>a[i];
        if(a[i]<400)s.insert("h");
        else if(a[i]<800)s.insert("ty");
        else if(a[i]<1200)s.insert("gr");
        else if(a[i]<1600)s.insert("mizu");
        else if(a[i]<2000)s.insert("ao");
        else if(a[i]<2400)s.insert("ki");
        else if(a[i]<2800)s.insert("ore");
        else if(a[i]<3200)s.insert("red");
        else free++;
    }
    ll mint,mx;
    if(s.empty()){
        mint=1;
        mx=free;
    }
    else {
        mint = s.size();
        mx = mint + free;
    }
    cout <<mint<<" "<<mx<<endl;
    return 0;
}