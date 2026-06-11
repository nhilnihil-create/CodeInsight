#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll k,t;cin>>k>>t;
    vector<ll> a(t);
    priority_queue<ll> que;
    rep(i,t){
        ll a;cin>>a;
        que.push(a);
    }
    ll tmp=0;//前日食ったものの種類の個数
    while(que.size()){
        ll a=que.top();que.pop();
        a--;
        if(tmp!=0)que.push(tmp);
        tmp=a;
    }
    cout<<tmp<<endl;
}