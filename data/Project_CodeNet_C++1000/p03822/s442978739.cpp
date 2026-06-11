#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<ll,ll> P;
#define pb push_back
#define ft first
#define sd second
#define mp make_pair
#define fr(i,n) for(int i=0;i<(n);i++)
#define Fr(i,n) for(int i=0;i++<(n);)
#define ifr(i,n) for(int i=(n)-1;i>=0;i--)
#define iFr(i,n) for(int i=(n);i>0;i--)

int n,a;
vector<int> v[100010];
bool f[100010]={};

int rec(int i){
    int b=0;
    vector<int> c;
    if(!f[i]) return 0;
    fr(j,v[i].size()) c.pb(rec(v[i][j]));
    sort(c.begin(),c.end());
    fr(j,v[i].size()){
        a=c[j]+v[i].size()-j;
        b=max(b,a);
    }
    return b;
}

int main(){
    cin>>n;
    Fr(i,n-1){
        cin>>a;
        v[a].pb(i+1);
        f[a]=1;
    }
    cout<<rec(1)<<endl;
}