#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include<random>
using namespace std;
#define N (1000000000+7)
#define M 998244353
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;
 
ll A(ll x){
    if(x>=0)return x;
    else return -x;
}
 
ll gcd(ll a, ll b) {
	if (b > a) {
		ll tmp = b;
		b = a;
		a = tmp;
	}
	if (a%b == 0)return b;
	else return gcd(b, a%b);
}



int main(void){
	ll n,a,b;
	cin>>n>>a>>b;
	vector<ll>v(n);
	map<ll,ll>m1,m2;
	for(int i=0;i<n;i++){
		cin>>v[i];
		m1[v[i]]++;
	}
	double ans = 0.0;
	sort(v.begin(),v.end(),greater<ll>());
	set<ll>s;
	for(int i=0;i<a;i++){
		ans+=(double)v[i];
		s.insert(v[i]);
		m2[v[i]]++;
	}
	printf("%.10lf\n",(double)ans/a);
	if(s.size()>1){
		ll ans1 = 1;
		for(auto itr = m2.begin();itr!=m2.end();++itr){
			ll v = itr->first;
			ll num = itr->second;
			ll ue = 1;
			ll shita = 1;
			for(ll i=1;i<=num;i++){
				ue*=(m1[v]-i+1);
				shita*=i;
				if(ue%shita==0){
					ue = ue/shita;
					shita = 1;
				} 
			}
			ans1*=ue;
		}
		cout<<ans1<<endl;
	}
	else{
		ll ans1 = 0;
		ll cnt = m1[v[0]];
		for(ll i=a;i<=b;i++){
			if(cnt<i)break;
			ll ue = 1;
			ll shita = 1;
			for(ll j=1;j<=i;j++){
				ue*=(cnt-j+1);
				shita*=j;
				if(ue%shita==0){
					ue = ue/shita;
					shita = 1;
				}
			}
			ans1+=ue;
		}
		cout<<ans1<<endl;
	}
    return 0;
}