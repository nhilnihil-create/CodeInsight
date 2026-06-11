#include <iostream>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n;i++)
ll d[300][300],v, n, c, e, u, k, sum = 0,ans;
int main(void) {
    ll a, b, c, sum = 0;
    cin >> a;
    rep(i, a) {
        cin >> b;
        sum += (b % 2);
    }
    sum %= 2;
    if (sum == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}