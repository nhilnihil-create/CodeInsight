#include<bits/stdc++.h>
using namespace std;

int main(){
	string A;
	cin >> A;
	int bit = 0;
	vector<int> par;
	for(int i = A.size() - 1; i >= 0; --i){
		int t = A[i] - 'a';
		bit |= (1<<t);
		if(bit + 1 == (1<<26)){
			par.push_back(i);
			bit = 0;
		}
	}
	int len = par.size();
	vector<char> ans;
	int now = 0;
	for(int i = len; i >= 0; --i){
		if(i != len){
			while(A[now] != ans[ans.size() - 1]) now++;
			now++;
		}
		bit = 0;
		if(i != 0){
			for(; now < par[i-1]; ++now){
				int t = A[now] - 'a';
				bit |= (1<<t);
			}
			for(int j = 0; j < 26; ++j){
				if(!(bit & (1<<j))){
					char c = 'a' + j;
					ans.push_back(c);
					break;
				}
			}
		}else{
			for(; now < A.size(); ++now){
				int t = A[now] - 'a';
				bit |= (1<<t);
			}
			for(int j = 0; j < 26; ++j){
				if(!(bit & (1<<j))){
					char c = 'a' + j;
					ans.push_back(c);
					break;
				}
			}
		}
	}
	
	for(int i = 0; i < ans.size(); ++i) cout << ans[i];
	return 0;
}