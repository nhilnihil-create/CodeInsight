#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod =(1e9)+7;
using P = pair<ll,ll>;

int main(){
   ll n;cin >>n;
   vector<ll>l;
   vector<ll>r;
    for (int i = 0; i < n; ++i) {
        ll a;cin >>a;
        if(i%2==0){
            r.push_back(a);
        }
        else {
            l.push_back(a);
        }
    }
    if(n%2==1)swap(r,l);
    reverse(all(l));
    for (int j = 0; j < l.size(); ++j) {
        cout <<l[j]<<" ";
    }
    for (int i = 0; i < r.size(); ++i) {
        cout <<r[i]<<" ";
    }
    cout <<endl;
}

