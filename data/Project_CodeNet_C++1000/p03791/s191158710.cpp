#include <iostream>

using namespace std;
int x[200010];
long long ans = 1,mod = 1000000007,j = 0;
int main(){
	int i,n;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> x[i];
	}
	for(i=0;i<n;i++){
		j++;
		if(x[i]==2*j - 2){
			(ans *= j) %= mod;
			j--;
		}
	}
	while(j){
		(ans *= j) %= mod;
		j--;
	}
	cout << ans << endl;
}