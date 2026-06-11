#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<climits>
#include<set>
#include<utility>
using namespace std;
typedef long long int ll;
 
int main(){

	ll n, a[200000], total=0, ans=1e12;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
		total+=a[i];
	}
	if(n==2){
		cout << abs(a[0]-a[1]) << endl;
		return 0;
	}
	ll tmp=0;
	for(int i=0; i<n-1; i++){
		total-=a[i];
		tmp+=a[i];
		ans=min(ans, abs(total-tmp));
	}
	
	cout << ans << endl;

	return 0;
}
