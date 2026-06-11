#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template <class T, class U> using Pa = pair<T, U>;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

int main(){
    ll N;
    cin >> N;
    vec<ll> A(N);
    for(int i=0;i<N;i++) cin >> A[i];
    ll sum = accumulate(A.begin(),A.end(),0LL);
    ll num = N*(N+1)/2;
    if(sum%num!=0){
        cout << "NO\n";
        return 0;
    }
    vec<ll> D(N);
    for(int i=0;i<N;i++){
        D[i] = A[(i+1)%N]-A[i];
    }
    if(accumulate(D.begin(),D.end(),0LL)!=0){
        cout << "NO\n";
        return 0;
    }
    ll n = sum/num;
    ll s = 0;
    for(int i=0;i<N;i++){
        if(n-D[i]<0){
            cout << "NO\n";
            return 0;
        }
        if((n-D[i])%N!=0){
            cout << "NO\n";
            return 0;
        }
        s += (n-D[i])/N;
    }
    cout << (s==n? "YES\n":"NO\n");
}