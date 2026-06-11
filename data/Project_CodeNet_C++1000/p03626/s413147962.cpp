#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9+7;

int main(){
	int N;
	cin >> N;
	string S1,S2;
	cin >> S1 >> S2;

	int i=0;
	long long ans;
	if(S1.at(0)==S2.at(0)){
		ans=3;
		i=1;
	}
	else{
		ans=6;
		i=2;
	}
	for(;i<N;i++){
		if(S1.at(i-1)==S2.at(i-1)){
			if(S1.at(i)==S2.at(i))	ans=(ans*2)%MOD;
			else{
				ans=(ans*2)%MOD;
				i++;
			}
		}
		else{
			if(S1.at(i)==S2.at(i))	ans=ans;
			else{
				ans=(ans*3)%MOD;
				i++;
			}
		}
	}
	cout << ans << endl;

	return 0;
}
