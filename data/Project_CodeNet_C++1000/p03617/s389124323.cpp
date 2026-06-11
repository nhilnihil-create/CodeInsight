#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;

const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    long long  Q,H,S,D; cin >> Q >> H >> S >> D;
    long long  N; cin >> N;
    long long  ans = 0;
    long long  min1 = Q*4;
    if(min1 > H*2) min1 = H*2;
    if(min1 > S) min1 = S;

    if(D > min1*2) ans = (min1)*N;
    else ans = (N/2)*D + (N%2)*min1;
    cout << ans << endl;
}


