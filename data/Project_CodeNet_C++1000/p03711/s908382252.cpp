#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    int a[] = {0,1,3,1,2,1,2,1,1,2,1,2,1};
    int x,y;
    cin >> x >> y;
    if(a[x] == a[y])cout << "Yes\n";
    else cout << "No\n";
    return 0;
}