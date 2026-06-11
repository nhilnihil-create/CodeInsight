// In the name of ALlah //
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 * 5 + 10 , inf = 1e9;
int n , a[maxn] , cnt[maxn];
void solve(){
    int ans = 0;
    for (int i = 1; i <= 1e5; i ++){
        ans = max(cnt[i] + cnt[i - 1] + cnt[i + 1] , ans);
    }
    cout << ans;
}
void in (){
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        cnt[a[i]] ++;
    }
    solve();
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    in();
}
