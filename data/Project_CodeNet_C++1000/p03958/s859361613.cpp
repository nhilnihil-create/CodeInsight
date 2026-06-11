#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    int k,t;
    cin >> k >> t;
    vector<int>a(t);
    rep(i,t)cin >> a[i];
    sort(all(a));
    reverse(all(a));
    int ans = max(0,a[0]-1-(k-a[0]));
    cout << ans << endl;
    return 0;
}