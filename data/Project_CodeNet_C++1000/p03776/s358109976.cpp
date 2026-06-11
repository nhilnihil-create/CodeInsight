
#include<bits/stdc++.h>
using namespace std;
  #define ll long long
ll ans = 0,tmp=0,ave= 0;
ll COM(ll n, ll k){
    ll num=1;
    for(int i=0;i<k;i++) {
        num *= n-i;
        num /= (1+i);
    }
    return num;
}
int main()
{
  ll n,k,m;
  cin >> n >> k >> m;
  map<ll,ll>mp;
   vector<ll>V;
  ll ara[n+10];
  for(ll i=0; i<n; i++)
  {
      cin >> ara[i] ;
       V.push_back(ara[i]);
      mp[ara[i]]++;
  }
  sort(ara,ara+n);
  sort(V.begin(),V.end());
  ll sum = 0;
  for(ll i=n-1; i>=max(n-k,0*1LL); i--)
  {
      sum += ara[i];
  }
  printf("%f\n",sum*1.00/k*1.00);

      ll id1 = lower_bound(V.begin(), V.end(), V[n-k])-V.begin();
    if(id1!=n-k) {
        ll id2 = lower_bound(V.begin(), V.end(), V[n-k]+1)-V.begin();
        ans += COM(id2-id1, id2-(n-k));
        
        if(V[n-k]==V[n-1]) {
            for(int i=n-k-1;i>=max(n-m, id1);i--) {
                tmp = COM(id2-id1, id2-i);
                
                ans += tmp;
                //cout << id2-id1 << " " << id2-i << " " << tmp << endl;
            }
        }
    }
    cout << setprecision(18) << max(1LL, ans) << endl;

}
