#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;


int main(){
    fast_io

    int n;
    string s;
    cin>>s;
    n=s.length();
    map<char, int> mp;
    mp['N'];
    mp['E'];
    mp['W'];
    mp['S'];

    rep(i,n){
        if(s[i]=='N') mp['N']=1;
        else if(s[i]=='W') mp['W']=1;
        else if(s[i]=='E') mp['E']=1;
        else mp['S']=1;
    }
    if(mp['N']==mp['S'] && mp['E']==mp['W']){
        cout<<"Yes"<<endl;
    }
    else cout<<"No"<<endl;

    
    return 0;
}