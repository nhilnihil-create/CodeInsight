#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vec<ll> A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    ll ans = 1e18;
    ll val = 0,sum = 0;
    for(int i=0;i<N;i++){
        ll nsum = sum+A[i];
        if(i%2==0){
            if(nsum<=0){
                val += 1-nsum;
                nsum = 1;
            }
        }else{
            if(nsum>=0){
                val += nsum+1;
                nsum = -1;
            }
        }
        sum = nsum;
    }
    ans = min(ans,val);
    val = 0,sum = 0;
    for(int i=0;i<N;i++){
        ll nsum = sum+A[i];
        if(i%2==0){
            if(nsum>=0){
                val += nsum+1;
                nsum = -1;
            }
        }else{
            if(nsum<=0){
                val += 1-nsum;
                nsum = 1;
            }
        }
        sum = nsum;
    }
    ans = min(ans,val);
    cout << ans << "\n";
}