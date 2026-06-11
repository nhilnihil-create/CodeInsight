#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define DEBUG

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
#define VECi(type,A,N,i) vector<type> A(N+10,i)
#define VEC2(type,A,N,M) vector<vector<type>> A(N+10,vector<type>(M+10))
#define ALL(v) v.begin()+1, v.end()-9

int main(){
    ll N;
    cin>>N;
    
    
    VEC(ll,A,N);
    VEC(ll,B,N);
    REPR(i,N){
        cin>>A[i]>>B[i];
    }
    
    ll cnt=0;
    REP(i,N){
        A[i]+=cnt;
        if(A[i]%B[i]!=0){
            cnt+=B[i]-(A[i]%B[i]);
            A[i]+=B[i]-(A[i]%B[i]);
        }
    }
    cout<<cnt<<endl;
    //sort(ALL(C),[](auto& a, auto& b) {return a[2] < b[2];});
    //if(equal(D.begin(), D.end()-1, K.begin()))cout<<"Yes";else cout<<"No";
    return 0;
}
