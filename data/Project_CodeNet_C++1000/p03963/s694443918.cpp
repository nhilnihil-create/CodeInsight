#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using P = pair<string,int>;

int main() {
ll n,k;
cin >> n >> k;
ll ans = k;
ans *= pow(k-1,n-1);
cout << ans << endl;

}
