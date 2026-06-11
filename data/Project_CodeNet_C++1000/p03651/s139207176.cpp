#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int GCD(int a, int b){
    if(b == 0) return a;
    else return GCD(b, a%b);
}

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    int g = a[0];
    int mx = 0;
    //N個の要素すべてに対するGCDを求め、また、最大の要素を見つける
    rep(i, N){
        g = GCD(g, a[i]);
        mx = max(mx, a[i]);
    }

    if(K <= mx && K % g == 0) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}