#include<bits/stdc++.h>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define rall(c) (c).rbegin(),(c).rend()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    ll n;cin>>n;
    string s;cin>>s;
    bool f=0;
    bool b=(s[0]=='o');
    vector<int>w(n+1,0);
    if(!f){
        w[0]=1;w[1]=1;
        REP(i,1,n){
            if(s[i]=='o'){
                if(w[i]==1)w[i+1]=w[i-1];
                else w[i+1]=-w[i-1];
            }else{
                if(w[i]==1)w[i+1]=-w[i-1];
                else w[i+1]=w[i-1];
            }
        }
        if(w[n]!=w[0]);
        else{
            if(b){
                if(w[1]==w[n-1])f=1;
            }else{
                if(w[1]!=w[n-1])f=1;
            }
        }
    }
    if(!f){
        rep(i,n+1)w[i]=0;
        w[0]=1;w[1]=-1;
        REP(i,1,n){
            if(s[i]=='o'){
                if(w[i]==1)w[i+1]=w[i-1];
                else w[i+1]=-w[i-1];
            }else{
                if(w[i]==1)w[i+1]=-w[i-1];
                else w[i+1]=w[i-1];
            }
        }
        if(w[n]!=w[0]);
        else{
            if(b){
                if(w[1]==w[n-1])f=1;
            }else{
                if(w[1]!=w[n-1])f=1;
            }
        }
    }
    if(!f){
        rep(i,n+1)w[i]=0;
        w[0]=-1;w[1]=1;
        REP(i,1,n){
            if(s[i]=='o'){
                if(w[i]==1)w[i+1]=w[i-1];
                else w[i+1]=-w[i-1];
            }else{
                if(w[i]==1)w[i+1]=-w[i-1];
                else w[i+1]=w[i-1];
            }
        }
        if(w[n]!=w[0]);
        else{
            if(b){
                if(w[1]!=w[n-1])f=1;
            }else{
                if(w[1]==w[n-1])f=1;
            }
        }
    }
    if(!f){
        rep(i,n+1)w[i]=0;
        w[0]=-1;w[1]=-1;
        REP(i,1,n){
            if(s[i]=='o'){
                if(w[i]==1)w[i+1]=w[i-1];
                else w[i+1]=-w[i-1];
            }else{
                if(w[i]==1)w[i+1]=-w[i-1];
                else w[i+1]=w[i-1];
            }
        }
        if(w[n]!=w[0]);
        else{
            if(b){
                if(w[1]!=w[n-1])f=1;
            }else{
                if(w[1]==w[n-1])f=1;
            }
        }
    }
    if(f){
        rep(i,n){
            if(w[i]==1)cout<<'S';
            if(w[i]==-1)cout<<'W';
        }
        cout<<endl;
    }else{
        cout<<-1<<endl;;
    }
}