#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,K;
    cin >> N >> K;
    vec<ll> A(N),B(N);
    for(int i=0;i<N;i++) cin >> A[i] >> B[i];
    ll ans = 0;
    vec<int> use(N,1);
    int h = 0;
    for(int i=0;i<30;i++) if(K>>i&1) h = i;
    for(int i=0;i<N;i++){
        int a = 0;
        for(int j=0;j<30;j++) if(A[i]>>j&1) a = j;
        if(a>h) use[i] = 0;
    }
    for(int k=h;k>=0;k--){
        ll now = 0;
        if(K>>k&1){
            for(int i=0;i<N;i++) if(use[i]){
                if(!(A[i]>>k&1)) now += B[i];
            }
        }
        if(!(K>>k&1)){
            for(int i=0;i<N;i++){
                if(A[i]>>k&1) use[i] = 0;
            }
        }
//        cerr << k << " " << ans << "\n";
        ans = max(ans,now);
    }
    ll s = 0;
    for(int i=0;i<N;i++) if(use[i]) s += B[i];
    ans = max(ans,s);
    cout << ans << "\n";
}