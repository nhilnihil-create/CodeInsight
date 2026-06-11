#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=int(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
#define rAll(x) (x).rbegin(),(x).rend()
using namespace std;
using ll = long long;

int main(){
    int N,M,K;cin>>N>>M>>K;
    for(int s=0;s<=N;++s) for(int t=0;t<=M;++t){
        if(t*s+(M-t)*(N-s)==K){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}