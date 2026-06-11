#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
const int MX = 100005;
using ll = long long;
int n, m, a[MX];
ll ans, k, s1[MX], s2[MX];
void add(int l ,int r){
	s1[l]++; s1[r]--;
	s2[l] -= l; s2[r] += l;
	if(r < l){
		s1[0]++;
		s2[0] -= l-m;
		s2[r] -= m;
	}
}
int main(){
	scanf("%d%d", &n, &m);
	rep(i,n) scanf("%d", a+i);
	rep(i,n-1){
		ans += (a[i+1] - a[i] + m) % m;
		add(a[i]%m, a[i+1]%m);
	}
	rep(i,m){
		if(i){
			s1[i] += s1[i-1];
			s2[i] += s2[i-1];
		}
		k = max(k, s1[i] * i + s2[i]);
	}
	printf("%lld\n", ans-k);
}