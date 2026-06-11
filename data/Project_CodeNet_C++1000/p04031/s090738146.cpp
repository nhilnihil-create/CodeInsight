#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < (n);i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;

int INF = 2e9;

int main(){
    int n;
    cin >> n;
    int res = 0;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    int ans = INF;
    for(int i = -100;i <= 100;i++){
        int sum = 0;
        rep(j,n){
            sum += pow(a[j]-i,2);
        }
        ans = min(ans,sum);
    }
    cout << ans << endl;
}