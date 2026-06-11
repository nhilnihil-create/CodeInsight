#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
ll N; scanf("%lld", &N);
vector<pair<ll,ll>> a(N); 
for(ll i = 0; i < N; i++){ scanf("%lld", &a[i].first); a[i].second = i+1;}

sort(a.begin(),a.end());

set<ll> se;

se.insert(0); se.insert(N+1);

ll ans = 0;

for(ll i = 0; i < N; i++){
 ll r = a[i].second; 
 se.insert(r);
 auto itr = se.lower_bound(r);
 auto itr1 = itr; auto itr2 = itr;
 
 itr1--; itr2++;
 
 ll res = (r-*itr1)*(*itr2-r);
 ans += res*a[i].first;
 
 }
 
 printf("%lld\n", ans);
 
 return 0;
 }

