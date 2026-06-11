#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define int long long
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
#define endl '\n'
typedef long long ll;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
signed main(){
    string s;cin>>s;
    vector<ll>a(4);
    rep(i,s.size()){
        if(s[i]=='N')a[0]=1;
        else if(s[i]=='S')a[1]=1;
        else if(s[i]=='W')a[2]=1;
        else a[3]=1;
    }
    if(a[0]==a[1]&&a[2]==a[3]){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}
