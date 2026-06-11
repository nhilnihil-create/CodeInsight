#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//二項係数の計算
int nCr(int A, int B) {
    ll ans = 1;
    for (int i = 0; i < B; i++) {
        ans*= A - i;
    }
    for (int i = 0; i < B; i++) {
        ans /= i + 1;
    }
    return ans;
}
int main() {
    ll A,B,C;
    cin>>A>>B>>C;
    if(A%2==0||B%2==0||C%2==0){
        cout<<0<<endl;
    }
    else{
        ll D=min(A*B,A*C);
        cout<<min(D,B*C)<<endl;
    }
}



