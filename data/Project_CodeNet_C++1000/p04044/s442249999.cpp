#include <bits/stdc++.h>
using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pl= pair<ll,ll>;
using ld=long double;
using V=vector<int>;
using Vl=vector<ll>;
using VV=vector<vector<int>>;
using VVl=vector<vector<ll>>;

int main(){
    int n,l;cin >>n>>l;
    vector<string>s(n);
    for (int i = 0; i < n; ++i) {
        cin >>s[i];
    }
    sort(all(s));
    string ans="";
    for (int i = 0; i < n; ++i) {
        ans+=s[i];
    }
    cout <<ans <<endl;
}
