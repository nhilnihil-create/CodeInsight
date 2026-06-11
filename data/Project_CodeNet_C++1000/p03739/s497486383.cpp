#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
typedef long long LL;
const LL INF=1e15;

int main(){
	int n;
	cin >> n;
	vector<LL> a(n);
	rep(i,n) cin >> a[i];
	LL sum=0, sign=1;
	LL res1=0, res2=0;
	rep(i,n){
		sum+=a[i];
		if(sum*sign<=0){
			res1+=abs(sum)+1;
			sum=sign;
		}
		sign*=-1;
	}
	sum=0, sign=-1;
	rep(i,n){
		sum+=a[i];
		if(sum*sign<=0){
			res2+=abs(sum)+1;
			sum=sign;
		}
		sign*=-1;
	}
	cout << min(res1,res2) << endl;

	return 0;
}