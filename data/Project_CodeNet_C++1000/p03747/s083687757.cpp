#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int in() {int x; cin>>x; return x;}
ll lin() {ll x; cin>>x; return x;}
string sin() {string x;cin>>x;return x;}
using graph = vector<vector<int>>;
using graph2 = vector<vector<pair<int, int>>>;

bool ifprime(int x){
    if(x==1)return false;
    if(x==2)return true;
    if(x%2==0)return false;
    for(int i=2;i*i<=x;i++){if(x%i==0)return false;}
    return true;
}
ll mod(ll x, ll y){if(x>=0||x%y==0) return x%y;return y+x%y;} //mod including minus
ll dv0(ll x, ll y){if(x>=0||x%y==0)return x/y;return x/y-1;} //rnd down
ll dv1(ll x, ll y){if(x%y==0) return dv0(x,y);return dv0(x,y)+1;} //rnd up

//Start from Here
int main(){
    ll N, L, T;
    cin>>N>>L>>T;
    ll X[N], W[N];
    ll a;
    rep(i, N){
        cin>>X[i]>>W[i];
        if(i==0){
            a=X[i];
            X[i]=0;
        }
        else{
            X[i]-=a;
        }
    }
    ll cnt=0;
    if(W[0]==1){
        rep(i,N){
            if(W[i]==2){
                cnt+=dv1(2*T-X[i], L);
                X[i]=mod(X[i]-2*T, L);
            }
        }
        sort(X, X+N);
        cnt%=N;
        rep(i, N){
            cout<<(X[(N-cnt+i)%N]+T+a)%L<<endl;
        }
    }
    else{
        rep(i, N){
            if(W[i]==1){
                cnt+=(X[i]+2*T)/L;
                X[i]=(X[i]+2*T)%L;
            }
        }
        sort(X, X+N);
        cnt%=N;
        rep(i, N){
            cout<<mod(X[(cnt+i)%N]-T+a, L)<<endl;
        }
    }
}