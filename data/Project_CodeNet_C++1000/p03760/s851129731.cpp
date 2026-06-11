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
    cin>>str1>>str2;
    if(str1.length()>str2.length()){
        cout<<str1[0];
        rep(i,str2.length()){
            cout<<str2[i]<<str1[i+1];
        }
    }
    else {rep(i,str1.length()){
        cout<<str1[i]<<str2[i];
    }}
ln;
    return 0;
}
