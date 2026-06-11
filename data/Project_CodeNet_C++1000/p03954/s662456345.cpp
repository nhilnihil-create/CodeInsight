#include<bits/stdc++.h>
using namespace std;
int n , nn , ans , a[200005] , b[200005] , maxn ;
bool fmid(int mid){
	for(int i = 1 ; i <= nn ; i++){
		if(a[i] < mid)
			b[i] = 0;
		else
			b[i] = 1;
	}
	int ans1 = 1e8 + 7;
	int ans2 = 1e8 + 7;
	for(int i = 1 ; i <= nn ; i++){
		if(b[i] == b[i + 1]){
			if(b[i]){
				ans1 = min(ans1 , min ( abs ( n - i ) , abs ( n - ( i + 1 ) ) ));
			} else{
				ans2 = min(ans2 , min ( abs ( n - i ) , abs ( n - ( i + 1 ) ) ));
			}
		}
	}
	if(ans1 == 1e8 + 7 && ans2 == 1e8 +7)
		return (n&1)==b[n];
	return ans1<ans2;
}

int main() {
	cin >> n ;
	nn = n * 2 - 1;
	for(int i = 1 ; i <= nn ; i ++){
		cin >> a[i];
	}
	int l = -1 , r = 1e8;
	while(r-l>1){
		int mid=(l+r)>>1;	
		if(fmid(mid)) l=mid;
		else r=mid;
	}	
	cout << l ;
}