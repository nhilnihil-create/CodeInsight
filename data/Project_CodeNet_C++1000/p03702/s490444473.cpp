#include <bits/stdc++.h>
#define all(v) (v).begin(),(v).end()
using namespace std;
using LL = long long;
// 型に合わせた値 2倍してもオーバーフローしないようにする
// const int INF = 1e9;
const LL INF = 1e10;

LL N, A, B;
vector<LL> h;

bool f(LL K){
    LL tmp = 0;
    for(int i=0; i<N; i++){
        LL rem = h[i]-B*K;
        if(rem > 0) tmp += (rem+(A-B-1)) / (A-B);
    }
    return (tmp <= K);
}

LL binary_search(LL ok, LL ng){
    while (abs(ok - ng) > 1) {
        LL mid = (ok + ng) / 2;
        if(f(mid)) ok = mid;
        else ng = mid;
    }
    return ok;
}

int main(){
    cin >> N >> A >> B;
    h = vector<LL>(N);     // サイズNを確保
    for(int i=0; i<N; i++) cin >> h[i];
    cout << binary_search(INF, 0) << endl;
}
