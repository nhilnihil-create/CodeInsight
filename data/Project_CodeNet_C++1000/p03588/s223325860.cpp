#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n),b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    cout << a[0]-1+b[0]+a[n-1]-a[0]+1 << endl;
    return 0;
}