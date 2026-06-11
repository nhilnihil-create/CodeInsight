#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long MOD = 1000000007LL; // 998244353LL;

// Repeat
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
// Container Util
#define ALL(v) (v).begin(), (v).end()
#define SORT(v) sort((v).begin(),(v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())

int main() {
    int A,B,C; cin >> A >> B >> C;
    map<int,int> mp;
    mp[A]++; mp[B]++; mp[C]++;

    cout << mp.size() << endl;
    
    return 0;
}