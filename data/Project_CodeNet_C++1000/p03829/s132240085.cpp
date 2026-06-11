#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define badi_val 1000000007
int n;
int pd[1100];
const int mo=1e9+7;
int main(){
	int n , a , b;
	cin >> n >> a >> b;
	long long arr[n];
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];
	//sort(arr , arr + n);
	long long ans = 0;
	for(int i = 0 ; i < n - 1;i++){
		ans += min((arr[i+1] - arr[i])*a*1ll , b*1ll);
	}
	cout << ans << endl;
 	return 0; 
}