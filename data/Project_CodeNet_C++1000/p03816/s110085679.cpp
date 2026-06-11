#include<iostream>
#include<iomanip>
#include<cstdio>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<cmath>
#include<numeric>

using namespace std;
typedef long long ll;
template <class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return 1;} return 0;}
template <class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return 1;} return 0;}


/*
同じのが3枚あったらそれを対消滅 -> 1枚に
同じのが4枚あったらそれを対消滅-> 2枚に
これはそれぞれ1ずつ

同じのが2枚あるセクションがk個あったら
k/2はそれぞれ1ずつで完了する-> (k+1)/2 で切り上げればよーし
*/

int main() {
    int N; cin >> N;
    vector<int> a(N), c(N+2,0);
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a.begin(),a.end());
    for (int i = 0; i < N; i++) {
        int tmp = a[i], j = i;
        while (i+1 < N && a[i+1] == tmp) i++;
        c[i-j+1]++;
    }
    int res = 0;
    for (int i = N-1; i >= 2; i--) {
        c[i] += c[i+2];
        res += c[i+2];
    }
    res += c[3] + (c[2]+1)/2;
    cout << N - 2 * res << endl;
    
}