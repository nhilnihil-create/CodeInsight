#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
int id;
deque<int>S1,S2;
void Dfs(int x){
	if(x == 1)return;
	Dfs(x >> 1);
	id++;
	S1.push_front(id);
	S2.push_front(id);
	if(x & 1){
		id++;
		S1.push_back(id);
		S2.push_front(id);
	}
}
signed main(){
#ifdef Sirius
	freopen("in","r",stdin);
#endif 
	cin >> n;
	Dfs(n + 1);
	cout << S1.size() + S2.size() << endl;
	while(S1.size())cout << S1.front() << " ",S1.pop_front();
	while(S2.size())cout << S2.front() << " ",S2.pop_front();
	cout << endl;
	return 0;
}
