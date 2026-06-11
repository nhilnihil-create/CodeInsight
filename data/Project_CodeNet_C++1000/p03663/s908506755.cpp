#include <iostream>
#include <string>
using namespace std;

long long binsearch(long long ans,long long digit){
	string s;
	long long dig = 1;
	for(int i=0;i<digit;i++){
		dig *= 10;
	}
	int lb = 10,ub = -1;
	while(lb-ub>1){
		long long mid = (lb+ub)/2;
		if(digit==0 && mid==0){
			return 1000;
		}
		cout << "? " << (ans*10+mid)*(10000000000/dig) << endl;
		cin >> s;
		if(s[0]=='Y'){
			lb = mid;
		}else{
			ub = mid;
		}
	}
	if(lb==10){
		return 100;
	}
	return lb;
}
	
int main(){
	long long i,j,n,ans=0,ans1;
	string s;
	for(i=0;i<9;i++){
		int n = binsearch(ans,i);
		if(n==1000){
			ans = 9;
			for(i=0;i<20;i++){
				cout << "? " << ans << endl;
				cin >> s;
				if(s[0]=='Y'){
					cout << "! " << (ans+1)/10 << endl;
					return 0;
				}else if(ans>1000000000){
					cout << "! " <<  1000000000 << endl;
					return 0;
				}
				ans = ans*10+9;
			}
		}
		if(n==100){
			ans = ans*10 + 9;
			continue;
		}else if(n==0){
			ans = ans*10;
		}else{
			ans = ans*10 + n-1;
		}
		cout << "? " << ans+1 << endl;
		cin >> s;
		if(s[0]=='Y'){
			ans++;
			ans1 = ans;
			for(j=0;j<10;j++){
				ans *= 10;
				cout << "? " << ans << endl;
				cin >> s;
				if(s[0]=='N'){
					cout << "! " << ans/10 << endl;
				    return 0;
				}
				if(s[0] == 'Y' && ans > 1000000000){
					cout << "! " << ans1 << endl;
					return 0;
				}
			}
		}
	}
}