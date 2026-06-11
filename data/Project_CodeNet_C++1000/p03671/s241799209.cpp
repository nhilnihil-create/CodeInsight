#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int a, b, c; cin >> a >> b >> c;
    int ans = min(a+b, b+c);
    ans = min(ans, a+c);
    cout << ans << endl;
}