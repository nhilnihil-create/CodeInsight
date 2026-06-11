#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;
// const ll INF = 1000000000000000000LL;

int main() {
    ll n,k;
    cin >> n >> k;
    vector<pair<int,int>> pr(n);
    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        pr[i].first = a;
        pr[i].second = b;
    }
    sort(pr.begin(),pr.end());
    int ans;
    for(int i=0;i<n;i++){
        k-=pr[i].second;
        if(k<=0){
            ans = pr[i].first;
            break;
        }
    }
    cout << ans << endl;
}

