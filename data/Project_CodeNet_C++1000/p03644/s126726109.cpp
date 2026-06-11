#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//二項係数の計算
int nCr(int A, int B) {
    ll ans = 1;
    for (int i = 0; i < B; i++) {
        ans *= A - i;
    }
    for (int i = 0; i < B; i++) {
        ans /= i + 1;
    }
    return ans;
}
int main() {
    int N;
    cin>>N;
    int ans=1;
    bool a=true;
    while(a==true){
        if(N<ans*2){
            a=false;
        }
        else{
            ans*=2;
        }
    }
    cout<<ans<<endl;
}