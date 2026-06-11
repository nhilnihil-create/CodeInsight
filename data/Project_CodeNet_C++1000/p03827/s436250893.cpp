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
    vector<char>A(N);
    int cnt=0;
    int ans=0;
    rep(i,N){
        cin>>A[i];
        if(A[i]=='D'){
            cnt--;
        }
        else{
            cnt++;
        }
        if(ans<cnt){
            ans=cnt;
        }
    }
    cout<<ans<<endl;
}