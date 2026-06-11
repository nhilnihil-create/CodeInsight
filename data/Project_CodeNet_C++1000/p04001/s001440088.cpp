#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<climits>
#include<numeric>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<map>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define VSORT(v) sort(v.begin(), v.end());
#define VE vector<int>
#define VEP vector<pair<int,int>>
#define llong long long
#define pb(a) push_back(a)
using namespace std;
const vector<VE> DIR{ {-1,0},{1,0},{0,-1},{0,1} };
const int z = 1000000007;
long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}
int main() {
    string str;
    cin >> str;
    llong ans = 0;
    for (int bit = 0; bit < pow(2, str.size()-1); ++bit) {
        llong tmp_ans = static_cast<int>(str[0]-'0');
        REP(i, str.size() - 1) {
            if (bit & (1 << i)) {
                ans += tmp_ans;
                tmp_ans = static_cast<int>(str[i + 1] - '0');
            } else {
                tmp_ans = 10 * tmp_ans + static_cast<int>(str[i + 1] - '0');
            }
        }
        ans += tmp_ans;
    }
    cout << ans << endl;
    
}
