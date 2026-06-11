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

int main(){
    string a;
    cin>>a;
    int n=a.length(),s=1,m[200010]={},t=-1,u,ka;
    vector<int> v[26];
    bool f[26]={},g;
    fr(i,n) v[a[i]-'a'].pb(i);
    fr(i,26) v[i].pb(n);
    m[n]=0;
    ifr(i,n){
        m[i]=s;
        f[a[i]-'a']=1;
        g=1;
        fr(j,26) g=g&&f[j];
        if(g){
            s++;
            fr(j,26) f[j]=0;
        }
    }
    u=s;
    fr(i,s){
        fr(j,26){
            ka=(*upper_bound(v[j].begin(),v[j].end(),t));
            if(m[ka]==u-1){
                cout<<(char)('a'+j);
                u--;
                t=ka;
                break;
            }
        }
    }
}