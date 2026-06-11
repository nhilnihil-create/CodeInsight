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
    ll h,w;
    cin>>h>>w;
    vector<string> stra(h);
    rep(i,h){
        cin>>stra[i];
    }
    rep(i,h){
        rep(j,2){
            cout<<stra[i]<<endl;
        }
    }

    return 0;
}
