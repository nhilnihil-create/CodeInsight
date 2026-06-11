#include<iostream>
#define ll long long
using namespace std;

ll MOD = 1e9 + 7;

int a[100005];

int main(){
	int n,d;
	cin >> n;
	int ans = 1;
	if(n%2 == 0){
		for(int i = 1; i<=n; i++){
			cin >> d;  
			a[d]++;
			if(d % 2 == 0 || a[d] > 2){
				ans = 0;
				break;
			}
			else if(a[d] == 1){
				ans = (ans*2) % MOD;
			}
		}
		cout << ans;
	}
	else{
		for(int i = 1; i<=n; i++){
			cin >> d;
			a[d]++;
			if(d % 2 ==1 || a[d] > 2 || (a[0] > 1)){
				ans= 0;
				break;
			}
			else if (a[d] == 1 && d != 0)
			{
				ans = (ans*2) % MOD;
			}
		}
		cout << ans;
	}
	
	return 0;
}  