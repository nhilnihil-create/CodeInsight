#include <iostream>
using namespace std;

int N,M,X[100010],count[100010] = {0},mod_count[100010] = {0};

int main(){
	cin >> N >> M;
	for(int i=1;i<=N;i++){
		cin >> X[i];
		count[X[i]]++;
		mod_count[X[i]%M]++;
	}
	int ans = 0;
	for(int i=0;i<M;i++){
		if(i==0){
			ans += mod_count[i]/2;
			mod_count[i] %= 2;
		}else{
			if(i!=M-i) ans += min(mod_count[i],mod_count[M-i]);
			else ans += mod_count[i]/2;
			if(mod_count[i]>=mod_count[M-i]){
				mod_count[i] -= mod_count[M-i];
				mod_count[M-i] = 0;
			}else{
				mod_count[M-i] -= mod_count[i];
				mod_count[i] = 0;
			}
		}
	}
//	cout << ans << endl;
	for(int i=1;i<=1e5;i++){
		if(count[i]>=2){
			if(mod_count[i%M]>=2){
				while(count[i]>=2 && mod_count[i%M]>=2){
					ans++;
					count[i] -= 2;
					mod_count[i%M] -= 2;
				}
			}
		}
	}
	cout << ans << endl;
}