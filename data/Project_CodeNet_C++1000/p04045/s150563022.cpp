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

    string n; cin >> n;
    ll k; cin >> k; set<ll> unlike;
    f(i,0,k)
    {
        ll x; cin >> x;
        unlike.insert(x);
    }
    ll add;
    f(i,0,10)
        if(unlike.count(i)==0)
        {
            add = i;
            break;
        }

    n = '0'+n;
   
    
    bool f = 0; ll ind=n.size();
    for(ll i=n.size()-1; i>=0; i--)
    {
        ll curr = (ll)(n[i]-'0');
        if( (i>0 && unlike.count( curr )) || f )
        {
            bool g = 1;
            f(j, curr+1, 10 )
            {
                if( unlike.count( j )==0 ){
                    n[i]= (char)(j+48);
                    f=0,g=0;
                    ind = i+1;
                    break;
                }
            }
            if(g)
                f=1;
        }
    }
    
    f(i,ind,n.size())
        n[i]=(char)(add+48);

    if(n[0]=='0')
        cout << n.substr(1,n.size()-1);
    else
        cout << n << endl;
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