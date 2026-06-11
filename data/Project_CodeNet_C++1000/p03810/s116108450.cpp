#include <bits/stdc++.h>
using namespace std;

template<typename T> T gcd(T x,T y){return y!=0?gcd(y,x%y):x;}
template<typename T> T lcm(T x,T y){return x/gcd(x,y)*y;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<int> A(N);
    for (int i=0;i<N;++i) cin >> A[i];
    if (N==1){cout << "Second" << '\n'; return 0;}
    for (int first=1;;first^=1){
        long long sum=0; int even=0,one=0,g=0,nxt;
        for (int i=0;i<N;++i){
            sum+=A[i]-1;
            if (A[i]==1) one=1;
            if (A[i]&1) nxt=i;
            else ++even;
        }
        if (one){cout << ((sum&1LL)^first?"Second":"First") << '\n'; return 0;};
        if (even&1){cout << (first?"First":"Second") << '\n'; return 0;}
        if (N-even>1){cout << (first?"Second":"First") << '\n'; return 0;}
        --A[nxt];
        for (int i=0;i<N;++i) g=gcd(g,A[i]);
        for (int i=0;i<N;++i) A[i]/=g;
    }
}