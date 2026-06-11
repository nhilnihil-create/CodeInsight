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
    int n,m;cin >>n>>m;
    vector<int>cnt(n,0);
    for (int i = 0; i < m; ++i) {
        int a,b;cin >>a>>b;
        a--;b--;
        cnt[a]++;
        cnt[b]++;
    }
    for (int i = 0; i < n; ++i) {
        cout <<cnt[i]<<endl;
    }
}