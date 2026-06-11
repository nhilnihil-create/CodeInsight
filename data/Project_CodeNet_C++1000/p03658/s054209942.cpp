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
    int n,k;cin >>n>>k;
    vector<int>l(n);
    for (int i = 0; i < n; ++i) {
        cin >>l[i];
    }
    sort(all(l));
    reverse(all(l));
    int ans=0;
    for (int i = 0; i < k; ++i) {
        ans+=l[i];
    }
    cout <<ans <<endl;
    return 0;
}