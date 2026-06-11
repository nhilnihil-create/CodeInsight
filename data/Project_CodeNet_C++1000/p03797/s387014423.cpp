#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
int main(){
    ll N, M;
    cin >> N >> M;
    if(N > M / 2){
        cout << M / 2 << endl;
    }
    else if(N < M / 2){
        cout << N + (M - 2* N) / 4 << endl;
    }
    else{
        cout << N << endl;
    }
    return 0;
}