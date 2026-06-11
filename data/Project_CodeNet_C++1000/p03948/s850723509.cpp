#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define forr(i,p,n) for(ll i=p;i<n;i++)
#define tam 310010
#define offset 30010
using namespace std;
typedef long long  ll;
typedef pair<ll,ll> ii;
typedef pair<map<int,int> ,int> mi;
typedef pair<ii,ii> iiii;
typedef vector<ll> vi;
const ll MOD=1e9+7;
int v[tam],valmax[tam];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int n,t;
    cin>>n>>t;
    forr(i,0,n)
    {
        cin>>v[i];
    }
    int maxx=-1,totmax=-1;
    for(int i=n-1;i>=0;i--)
    {
        valmax[i]=maxx-v[i];
        totmax=max(valmax[i],totmax);
        maxx=max(maxx,v[i]);
    }
    int c=0;
    forr(i,0,n)
    {
        if (totmax==valmax[i])c++;
    }
    cout<<c<<endl;
}