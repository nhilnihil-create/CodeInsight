#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define INF 1e9
#define MAXN 100005
#define MAXM 100005
#define MOD 1000000007
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define rep(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define pii pair<int, int>

ll ans,A,B,C;

void solve(){
    if(A * B * C % 2 == 0)
        cout << 0 << endl;
    else
        cout << min({A*B, B*C, C*A}) << endl;
}

int main(){
    cin >> A >> B >> C;

    solve();
}
