#include <bits/stdc++.h>
//#include <boost/range/algorithm/find_if.hpp>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;
const int INF = 999999999;

int main(){
    ll Q, H, S, D, N;
    cin >> Q >> H >> S >> D >> N;
    if(Q * 2 <= H){
        H = 2 * Q;
    }
    if(H * 2 <= S){
        S = 2 * H;
    }
    if(S * 2 <= D){
        D = 2 * S;
    }
    cout << (N/2)*D + (N%2)*S << endl;
return 0;}
/**
 * g++ code.cpp
 * ./a.out
 * shift + ctrl + i
**/ 
