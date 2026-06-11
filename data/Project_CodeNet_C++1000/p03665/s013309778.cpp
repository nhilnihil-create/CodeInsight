#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const ll INF = 1e16;

void solver(int N, int P, vector<int> &A, ull &ans){

    int even{};
    for(int i = 0; i != N; ++i){
        if(A.at(i)%2 == 0){
            ++even;
        }
    }

    ull base = 1;
    for(int i = 1; i <= N; ++i){
        base *= 2;
    }

    if(even == N){
        if(P == 0){
            ans = base;
        }
        else{
            ans = 0;
        }
    }
    else{
        ans = base/2;
    }
    return;
}

int main(){

    int N, P;
    cin >> N >> P;
    vector<int> A(N);
    for(int i = 0; i < N; ++i){
        cin >> A.at(i);
    }

    ull ans;
    solver(N, P, A, ans);

    cout << ans << endl;
    return 0;
}
