#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;
const ll C = 1e9+7; //10の9乗

int main(){
    //C2つでSが作れる
    ll N, M;
    cin >> N >> M;

    //Sが多い時
    if(N * 2 > M) {
        cout << M / 2;
        return 0;
    }

    //Cが多いとき
    ll count = 0;
    M -= N * 2;
    count += N;
    count += M / 4;
    cout << count << endl;
}