#include<bits/stdc++.h>
using namespace std;

long long N;
long long p[100005];

int main(){
	cin >> N;
	for(long long i = 0; i < N; i++){
		cin >> p[i];
		p[i]--;
	}
	
	long long ans = 0;
	bool flag = false;
	long long tmp = 0;
	for(long long i = 0; i < N; i++){
		if(p[i] == i){
			tmp++;
			flag = true;
		}else{
			if(flag){
				ans += (tmp + 1)/2;
				tmp = 0;
				flag = false;
			}
		}
	}
	if(flag){
		ans +=(tmp + 1)/2;
		tmp = 0;
		flag = false;
	}
	cout << ans << endl;
}
