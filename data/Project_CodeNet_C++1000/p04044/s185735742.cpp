#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define F first
#define S second
#define endl "\n"
#define nl cout<<endl
#define pb push_back
#define f(i,a,b) for(ll i=a;i<b;i++)
#define Knucklehead ios_base::sync_with_stdio(false);cin.tie(NULL);
#define txti freopen("input.txt", "r", stdin);
#define txto freopen("output.txt", "w", stdout);
//#define mod 100000007

#define mat vector<vector<ll>>
mat cn(ll n, ll m){return vector< vector<ll> >(n, vector<ll>(m));}
bool compare(char &s1,char &s2){return s1 > s2;} 

bool sortmahstyle(const pair<ll,ll> &a,  const pair<ll,ll> &b) 
{ 
    if(a.second > b.second )
        return true;
    if( a.second==b.second && a.first > b.second )
       return true;
 
    return false;
 }
//me
ll const mod = 1e9;
ll const inf = 2e5+1;

void solve()
{   

    ll n,l; cin >> n >> l;

    string a[n]; f(i,0,n) cin>> a[i];

    sort(a,a+n);
    f(i,0,n)
        cout << a[i];
    nl;
}

int main() {
Knucklehead 
//*
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
/**/


        
        ll t;
        /**/t=1;
        /*/cin>>t;/**/
        f(testcases,0,t){
            solve();
        }
 
 
 
 
    return 0;
}