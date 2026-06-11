#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000



int main(){
	
	int N;
	cin>>N;
	
	vector<int> x(N);
	
	int ans = 1;
	int now = 1;
	for(int i=0;i<N;i++){
		cin>>x[i];
	}
	
	for(int i=0;i<N;i++){
		ans = mod(ans * now);
		if(i==0){
			x[i]=1;
			now++;
		}
		else{
			if(x[i-1]+2 <= x[i]){
				x[i] = x[i-1]+2;
				now++;
			}
			else{
				x[i] = x[i-1];
			}
		}
		
	}
	
	cout<<ans<<endl;


	return 0;
}