#include <algorithm>
#include <vector>
#include <deque>
#include <bits/stdc++.h>
using namespace std;
int main(){
	int N, M; 
	cin >> N >> M; 
	vector<int> E[100010] = {}; 
	int X = 0, Y = 0; 
	for(int i = 0; i < M; i++){
		int a, b; 
		cin >> a >> b; 
		E[a].push_back(b); 
		E[b].push_back(a); 
		if(i == 0){
			X = a, Y = b; 
		}
	}
	vector<int> bef = {X}; 
	vector<int> aft = {Y}; 
	bool used[100010] = {}; 
	used[X] = true; used[Y] = true; 
	for(int i = 0; i < 1145141919; i++){
		int s = bef.at(bef.size()-1); 
		bool finished = true; 
		for(int j = 0; j < E[s].size(); j++){
			if(!used[E[s].at(j)]){
				finished = false; 
				used[E[s].at(j)] = true; 
				bef.push_back(E[s].at(j)); 
				break;
			}
		}
		if(finished) break; 
	}
	for(int i = 0; i < 1145141919; i++){
		int s = aft.at(aft.size()-1); 
		bool finished = true; 
		for(int j = 0; j < E[s].size(); j++){
			if(!used[E[s].at(j)]){
				finished = false; 
				used[E[s].at(j)] = true; 
				aft.push_back(E[s].at(j)); 
				break; 
			}
		}
		if(finished) break; 
	}
	cout << bef.size() + aft.size() << endl; 
	for(int i = bef.size() - 1; i >= 0; i--){
		cout << bef.at(i) << " "; 
	}
	for(int i = 0; i < aft.size(); i++){
		cout << aft.at(i) << " "; 
	}
}