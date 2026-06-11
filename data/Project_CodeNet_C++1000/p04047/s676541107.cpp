//
//  main.cpp
//  CP
//
//  Created by Shiv Pavan Raj on 22/02/20.
//  Copyright © 2020 Shiv Pavan Raj. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

#define SZ(x) ((int)(x).size())
#define FOR(it,c) for ( __typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++ )
using namespace std;
typedef pair<int,int> PII;
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
#define M 1000000007
#define MM 998244353
#define SZ(a) int((a).size())

using ll = long long;
using VI = vector<int>;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
using VLL = vector<ll>;
using ld = long double;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
      
}
const int MX = 2e5+10;
const int MX2 = 1e6+5;

ll INF= 4 * (ll)1e18;
int mx = 2 * (ll)1e9 + 10;


int main(int argc, const char * argv[]) {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0); // insert code here...
    int n;
    cin >> n;
    vector<int> a(2*n);
    for(int i = 0; i < 2 *n; ++i) cin >> a[i];
    sort(a.begin(),a.end());
    int ans= 0;
    for (int i=2*n - 2; i >= 0; i-=2) {
        ans = ans + a[i];
    }
    cout << ans << endl;
    return 0;
}





