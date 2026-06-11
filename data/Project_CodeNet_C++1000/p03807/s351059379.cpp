#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)

using namespace std;
using ll = long long;
using P = pair<int, int>;
using LP = pair<ll, ll>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    int cnt = 0;
    rep(i, n) {
        int a;
        cin>>a;
        if (a % 2 == 1) cnt++;
    }
    if (cnt % 2 == 1) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}