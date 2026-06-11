// lcmとかはg++ -std=c++17 default.cppみたいなかんじで
//vector<vector<ll>> piyo(tate,vector<ll> (yoko));

#include <bits/stdc++.h>
#define mod 1000000007
#define INF 100000001
#define ll long long
#define ln cout<<endl;
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl
#define double long double
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n) REP(i,0,n)
using namespace std;
int dp[120][1050];

int main() {
    cin.tie(0);
   	ios::sync_with_stdio(false);
    //double mini=INF;
    int maxi=0,f=0,sum=0,mini=INF;
    string str,str1,str2;
    int i;
    int n;
    int a,b,d,c;
    int e,weight;
        ll s;

    ll h,w;
    cin>>str;
    n=0;
    e=0;
    s=0;
    w=0;
    rep(i,str.length()){
        if(str[i]=='N') n=1;
        if(str[i]=='S') s=1;
        if(str[i]=='E') e=1;
        if(str[i]=='W') w=1;
    }
    if(n==1&&e==1&&s==1&&w==1){
        Yes;
    }
    else if(n==0&&e==1&&s==0&&w==1){
        Yes;
    }
    else if(n==1&&e==0&&s==1&&w==0){
        Yes;
    }else{
        No;
    }
    //cout<<sum<<endl;
    return 0;
}
