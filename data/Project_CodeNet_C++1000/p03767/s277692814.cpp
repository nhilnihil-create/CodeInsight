#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

#define REREASE

#define _GLIBCXX_DEBUG
#ifdef DEBUG
#define s(...) show(__VA_ARGS__);
#define sl(...) show(__VA_ARGS__);cout<<endl;
#else
#define s(...)
#define sl(...)
#endif
void show() {}
template <class Head,class... Args>void show(Head t,Args... args){std::cout<<t<<" ";show(args...);}
#define REP(i, n) for(ll i = 1; i <= n; i++)
#define REPR(i, n) for(ll i = n; i >= 1; i--)
#define FOR(i, m, n) for(ll i = m; i <= n; i++)
#define INF 1e9+123
#define VEC(type,A,N) vector<type> A(N+10)
#define VEC2(type,A,N,M) vector<vector<type>> A(N+10,vector<type>(M))
#define ALL(v) v.begin()+1, v.end()-9

int main(){
    int N;
    cin>>N;
    //vector<vector<ll>> C(N+10,vector<ll>(N));
    VEC(ll,a,3*N);
    REP(i,3*N){
        cin>>a[i];
    }
    
    sort(ALL(a),[](auto& a, auto& b) {return a > b;});
    ll sum=0;
    REP(i,N){
        sum+=a[2*i];
    }
    cout<<sum;
    //if(equal(D.begin(), D.end()-1, K.begin()))cout<<"Yes";else cout<<"No";
    return 0;
}
