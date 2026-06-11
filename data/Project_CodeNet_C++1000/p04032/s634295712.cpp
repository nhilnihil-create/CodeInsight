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
    string s;cin>>s;
    int n=s.size();
    rep(i,n-1){
        if(s[i]==s[i+1]){
            cout<<i+1<<" "<<i+2<<endl;
            return 0;
        }
        if(i==n-1)break;
        if(s[i]==s[i+2]){
            cout<<i+1<<" "<<i+3<<endl;
            return 0;
        }
    }
    cout<<-1<<" "<<-1<<endl;
}