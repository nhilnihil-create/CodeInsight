#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a.at(i);

	int flag = 0;
	int ans = 1;
	for(int i = 0; i < n-1; i++){
		if(a.at(i+1) < a.at(i)){
			if(flag == 1){
				ans++;
				flag = 0;
			}else{
				flag = -1;
			}
		}else if(a.at(i) < a.at(i+1)){
			if(flag == -1){
				ans++;
				flag = 0;
			}else{
				flag = 1;
			}	
		}
	}
	cout << ans << endl;
}