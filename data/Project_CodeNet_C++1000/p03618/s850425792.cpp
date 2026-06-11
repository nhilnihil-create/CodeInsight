#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 998244353;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt[26];
signed main(){
    string A;
    cin >> A;
    int N = A.size();
    int ans = (N*(N-1))/2;
    for(int i = 0; i < N; i++) {
        cnt[A[i]-'a']++;
    }
    for(int a:cnt) {
        ans -= (a*(a-1))/2;
    }
    cout << ans+1 << endl;
}