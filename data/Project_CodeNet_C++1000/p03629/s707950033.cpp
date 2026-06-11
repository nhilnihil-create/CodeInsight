#include<bits/stdc++.h>
using namespace std;

vector<int> C[26];

int search(int i, int now){
	int ng = -1, ok = C[i].size();
	while(ok - ng > 1){
		int mid = (ng + ok)/2;
		if(C[i][mid] > now) ok = mid;
		else ng = mid;
	}
	if(ok == C[i].size()) return -1;
	else return ok;
}

int main(){
	string A;
	cin >> A;
	int bit = 0;
	vector<int> par;
	int le[A.size()];
	for(int i = A.size() - 1; i >= 0; --i){
		int t = A[i] - 'a';
		bit |= (1<<t);
		if(bit + 1 == (1<<26)){
			par.push_back(i);
			bit = 0;
		}
		le[i] = par.size() + 1;
	}
	for(int i = 0; i < A.size(); i++){
		int t = A[i] - 'a';
		C[t].push_back(i);
	}
	int len = par.size();
	vector<char> ans;
	int now = -1;
	for(int i = 0; i < len + 1; ++i){
		for(int j = 0; j < 26; ++j){
			if(search(j, now) != -1){
				if(C[j][search(j, now)] == A.size() - 1){
					if(1 == len - i){
						char c = 'a' + j;
						ans.push_back(c);
						now = C[j][search(j, now)];
						break;
					}
				}else{
					if(le[C[j][search(j, now)] + 1] == len - i){
						char c = 'a' + j;
						ans.push_back(c);
						now = C[j][search(j, now)];
						break;
					}
				}
			}else{
				char c = 'a' + j;
				ans.push_back(c);
				break;
			}
		}
	}
	for(int i = 0; i < len + 1; ++i) cout << ans[i];
	return 0;
}