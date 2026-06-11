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

int main(){
    int a,b,c,d;cin>>a>>b>>c>>d;
    int x=abs(c-a);
    int y=abs(d-b);
    string s;
    if(a<c){
        if(b<d){
            rep(i,x)s+='R';rep(i,y)s+='U';
            rep(i,x)s+='L';rep(i,y)s+='D';
            s+='D';
            rep(i,x+1)s+='R';rep(i,y+1)s+='U';
            s+='L';s+='U';
            rep(i,x+1)s+='L';rep(i,y+1)s+='D';
            s+='R';
        }
        else{
            rep(i,x)s+='R';rep(i,y)s+='D';
            rep(i,x)s+='L';rep(i,y)s+='U';
            s+='U';
            rep(i,x+1)s+='R';rep(i,y+1)s+='D';
            s+='L';s+='D';
            rep(i,x+1)s+='L';rep(i,y+1)s+='U';
            s+='R';
        }
    }
    else{
        if(b<d){
            rep(i,x)s+='L';rep(i,y)s+='U';
            rep(i,x)s+='R';rep(i,y)s+='D';
            s+='D';
            rep(i,x+1)s+='L';rep(i,y+1)s+='U';
            s+='R';s+='U';
            rep(i,x+1)s+='R';rep(i,y+1)s+='D';
            s+='L';
        }
        else{
            rep(i,x)s+='L';rep(i,y)s+='D';
            rep(i,x)s+='R';rep(i,y)s+='U';
            s+='U';
            rep(i,x+1)s+='L';rep(i,y+1)s+='D';
            s+='R';s+='D';
            rep(i,x+1)s+='R';rep(i,y+1)s+='U';
            s+='L';
        }
    }
    cout<<s<<endl;
}