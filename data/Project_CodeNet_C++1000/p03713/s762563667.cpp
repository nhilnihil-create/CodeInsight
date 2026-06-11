#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(int I = (A); I < int(B); ++I)


ll cut_two(ll h,ll w){
	if(h%2==0) return (h/2)*w;
	if(w%2==0) return (w/2)*h;
	return (max(h,w)/2)*min(h,w); 
}


int main(){
	ll H,W;
	cin >> H >> W;
	ll ans = 100000000999;
	FOR(j,0,2){
		FOR(i,0,H){
			ll s1,s2,s3;
			s1 = i * W;
			s2 = cut_two((H-i),W);
			s3 = (H-i)*W - s2;
			ans = min(ans, max({s1,s2,s3}) - min({s1,s2,s3}) );
		}
		swap(H,W);
	}
	cout << ans << endl;
}