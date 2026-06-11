#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define pp pair<int,int>
#define ll long long
int inf=100000000;
ll INF=100000000000000000;
ll are=1000000007;

int main() {
    int n,ans=0;
    cin >> n;
    vector<int> a(n+1);
    rep(i,n) cin >> a.at(i+1);
    for (int i=2;i<n;i++){
        if (i==a.at(i)){
            if (i-1==a.at(i-1)) swap(a.at(i),a.at(i-1));
            else swap(a.at(i),a.at(i+1));
            ans++;
        }
    }
    if (a.at(1)==1) ans++;
    if (a.at(n)==n && n>=3) ans++;
    cout << ans << endl;
}
