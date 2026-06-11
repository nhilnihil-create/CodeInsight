#include<iostream>

using namespace std;
 
int main(){
	long long n,cnt=0,ans;
	
	cin >> n;
	ans = n;

	for(long long i = n; i > 0; i--){
		
		if(i % 2 == 0){
			long long acc=0,j = i;
			
			while(j % 2 == 0){
				j /= 2;
				acc++;
			}

			if(acc > cnt){
				ans = i;
				cnt = acc;
			}		
		}
	}

	cout << ans << endl;
}
