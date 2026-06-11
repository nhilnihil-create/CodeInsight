#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <cstdio>
#include <utility>
#include <bitset>

using namespace std;
typedef long long ll;

int main(){
	ll N,M;
	cin >> N >> M;
	vector<ll> x(N);
	for(int i=0;i<N;i++)
		cin >> x[i];
	sort(x.begin(),x.end());
	vector<ll> m(M,0);
	vector<ll> s(M,0);
	for(int i=0;i<N;){
		ll num = upper_bound(x.begin(),x.end(),x[i])-lower_bound(x.begin(),x.end(),x[i]);
		s[x[i]%M]+=num/2;
		m[x[i]%M]+=num;
		i+=num;
	}
	ll ans=0;
	for(int i=0;i<=M/2;i++){
		if(i==(M-i)%M){
			ans+=m[i]/2;
		}else{
			ll use = min(m[i],m[(M-i)%M]);
			ans+=use;
			s[i]=min(s[i],(m[i]-use)/2);
			s[(M-i)%M]=min(s[(M-i)%M],(m[(M-i)%M]-use)/2);
			ans+=max((ll)0,s[i]);
			ans+=max((ll)0,s[(M-i)%M]);
		}
	}
	cout << ans << endl;
	return 0;
}