#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000


int main(){

	int N;
	cin>>N;
	
	string s1,s2;
	cin>>s1>>s2;
	
	int ans = 1;
	int now = 0;
	
	while(true){
		if(now>=N)break;
		if(s1[now]==s2[now]){
			if(now==0){
				ans = mod(ans * 3);
			}
			else{
				if(s1[now-1]==s2[now-1]){
					ans = mod(ans * 2);
				}
			}
			now++;
		}
		else{
			if(now==0){
				ans = mod(ans * 6);
			}
			else{
				if(s1[now-1]==s2[now-1]){
					ans = mod(ans * 2);
				}
				else{
					ans = mod(ans * 3);
				}
			}
			now+=2;
		}
	}
	
	cout<<ans<<endl;
		
	
    return 0;
}

