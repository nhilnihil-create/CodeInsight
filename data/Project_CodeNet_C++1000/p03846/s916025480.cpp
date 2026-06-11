#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

ll modpow(ll a,ll n,ll m){
    ll res=1;
    while(n){
        if(n&1)res=res*a%m;
        a=a*a%m;
        n>>=1;
    }
    return res;
}

int main(){
    int n;cin>>n;
    vin num(100000);
    rep(i,n){
        int a;cin>>a;
        num[a]++;
    }
    if(n%2){
        if(num[0]!=1){
            cout<<0<<endl;
            return 0;
        }
        rep2(i,1,n){
            if(i%2==0&&num[i]!=2){
                cout<<0<<endl;
                return 0;
            }
            else if(i%2&&num[i]!=0){
                cout<<0<<endl;
                return 0;
            }    
        }
    }
    else{
        rep(i,n){
            if(i%2&&num[i]!=2){
                cout<<0<<endl;
                return 0;
            }
            else if(i%2==0&&num[i]!=0){
                cout<<0<<endl;
                return 0;
            }    
        }
    }
    cout<<modpow((ll)2,(ll)(n/2),(ll)inf)<<endl;
}