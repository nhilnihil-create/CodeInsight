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
                if(X[i]-2*T>0){
                    X[i]=(X[i]-2*T)%L;
                }
                else{
                    cnt+=(2*T-X[i])/L+1;
                    X[i]=L+(X[i]-2*T)%L;
                }
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
            if(X[(cnt+i)%N]-T+a>=0)
            cout<<(X[(cnt+i)%N]-T+a)%L<<endl;
            else{
                if((X[(cnt+i)%N]-T+a)%L==0){
                    cout<<0<<endl;
                }
                else{
                cout<<L+(X[(cnt+i)%N]-T+a)%L<<endl;
                }
            }
        }
    }
}