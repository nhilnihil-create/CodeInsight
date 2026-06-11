#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    int n,c,k;
    cin>>n>>c>>k;
    vector<int> t(n);
    rep(i,n) cin>>t[i];

    sort(all(t));
    int ans=0;
    int i=0;
    while(i<n){
        ans++;
        int start=i;
        while(i<n && t[i]-t[start]<=k && i-start<c) i++;
    }

    cout<<ans<<endl;
}