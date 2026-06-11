#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb push_back
#define ss second
#define ff first 
#define ub upper_bound
#define lb lower_bound
// #define mp make_pair
const ll M=1000000007;
ll power(ll x,ll n){if(n==0)return 1;else if(n%2==0)return (power((x*x)%M,n/2))%M;else return ((x%M)*power(x,n-1)%M);}
ll ncr(int n,int r){if(r>n)return 0;if(r > n - r) r = n - r;ll ans = 1;
int i;for(i = 1; i <= r; i++){ans *= n - r + i;ans /= i;}return ans;}
ll nCrModpDP(ll n, ll r, ll p){ 
    ll C[r+1]; 
    memset(C, 0, sizeof(C)); 
    C[0] = 1;
    for (ll i = 1; i <= n; i++){ 
        for (ll j = min(i, r); j > 0; j--) 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 
ll ncrmod(ll n, ll r, ll p){ 
   if (r==0) 
      return 1; 
   ll ni = n%p, ri = r%p; 
   return (ncrmod(n/p, r/p, p) * 
           nCrModpDP(ni, ri, p)) % p;  
} 
ll modInverse(ll a,ll m) 
{ 
   ll m0 = m; 
   ll y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
       ll q = a / m; 
       ll t = m; 
        m = a % m, a = t; 
        t = y; 
        y = x - q * y; 
        x = t; 
    } 
    if (x < 0) 
       x += m0; 
  
    return x; 
} 
ll fun(ll num[],ll sum,ll n){
map<ll,ll>mp;
for(int i=0; i<n; i++){
mp[num[i]]++;
}
ll ans=0;
for(int i=0; i<n; i++){
if(mp[sum-num[i]]>0&&(sum-num[i]!=num[i])&&(mp[num[i]]>0)){
ans+=1,mp[sum-num[i]]--,mp[num[i]]--;
}
else if(mp[sum-num[i]]>=2&&(sum-num[i]==num[i])){
ans+=1,mp[sum-num[i]]-=2;
}
}
return ans;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll n,k;
cin>>n>>k;
ll ans=k;
for(ll i=2; i<=n; i++){
ans*=(k-1);
}
cout<<ans;
return 0;
}