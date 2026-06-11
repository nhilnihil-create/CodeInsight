//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod =1e+9+7;

const int dy[4]={0,1,0,-1};
const int dx[4]={1,0,-1,0};
const ll INF=1e10;

int main(){
    ll n; cin>>n;
    string s; cin>>s;
    ll cntl=0,cntr=0;
    ll mn=0;
    rep(i,s.size()){
        if(s[i]=='(')cntl++;
        else cntr++;
        mn=min(mn,cntl-cntr);
    }
    rep(i,abs(mn)){
        cout<<"(";
    }
    cntl+=abs(mn);
    cout<<s;
    rep(i,abs(cntr-cntl)){
        cout<<")";
    }
    cout<<endl;
}









