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
   string o,e;cin >>o>>e;
    for (int i = 0; i < e.size(); ++i) {
        cout <<o[i]<<e[i];
    }
    if(o.size()!=e.size())cout<<o.back()<<endl;
}
