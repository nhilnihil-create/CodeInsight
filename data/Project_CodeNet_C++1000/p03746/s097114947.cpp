#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

int main()
{
	int n,m;
	cin>>n>>m;
	vector<queue<int>> g(n);
	int front,back;
	vector<int> flag(n,0);
	deque<int> path;
	for(int i = 0; i < m; i++){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		g[a].push(b);
		g[b].push(a);
		if(i==0){
			front=a;
			back=b;
			flag[a]++;
			flag[b]++;
			path.push_front(front);
			path.push_back(back);
		}
	}

	while(1){
		while(!g[front].empty() && flag[g[front].front()]>0) g[front].pop();
		if(!g[front].empty()){
			int x = g[front].front();g[front].pop();
			front = x;
			flag[x]++;
			path.push_front(x);
		}else break;
	}
	while(1){
		while(!g[back].empty() && flag[g[back].front()]>0) g[back].pop();
		if(!g[back].empty()){
			int x = g[back].front();g[back].pop();
			back = x;
			flag[x]++;
			path.push_back(x);
		}else break;
	}

	cout << path.size() << endl;
	int cnt=0;
	for(auto itr = path.begin(); itr != path.end(); ++itr){
		cnt++;
		cout << *itr+1 << (cnt==path.size()?"\n":" ");
	}


	return 0;
}