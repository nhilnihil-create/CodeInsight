// nb_9960
#include <bits/stdc++.h> 
using namespace std; 
#define fi(i,a,n) for (ll i=a; i < n; i++) 
#define ll long long
#define pb push_back 
#define mp make_pair 
#define F first 
#define S second 
#define all(x) x.begin(), x.end() 
#define clr(x) memset(x, 0, sizeof(x)) 
#define sortall(x) sort(all(x)) 
typedef pair<ll, ll> pl; 
typedef vector<ll> vl; 
typedef vector<pl> vpii; 
#define sz(a) int((a).size())
#define tr(c,i) for(typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c,x) (c.find(x) != c.end())
#define cpresent(c,x) (find(all(c),x) != c.end())

int main() 
{  
  ios_base::sync_with_stdio(0); 
  cin.tie(0); 
  cout.tie(0); 

  ll t = 1; 
  // cin >> t;

  while (t--) { 
    ll n;
    cin>>n;
    ll t[n],sum=0;
    fi(i,0,n){
    cin>>t[i];
    sum+=t[i];
    }
    ll m;
    cin>>m;
    fi(i,0,m){
      ll p,x;
      cin>>p>>x;
      cout<<sum-t[p-1]+x<<endl;
    }
  } 
  return 0; 
} 
