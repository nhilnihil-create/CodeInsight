#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<ll> A(N);
    for (int i=0;i<N;++i) cin >> A[i];
    ll cnt=0,ans=0;
    for (int i=0;i<N;++i){
        ans+=(A[i]-1)/(cnt+1);
        if (cnt+1==A[i]||!i) ++cnt;
    }
    cout << ans << '\n';
}