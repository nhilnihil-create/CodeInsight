#include <bits/stdc++.h>
using namespace std;

int n, a, b;
vector<int> e[100004];
int coloring[100004];
int main() {
	cin>>n;
	for(int i = 0 ; i<n-1;i++){
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	memset(coloring,-1,sizeof(coloring));
	queue<int> q;
	int b = 1, w = 1;
	coloring[1] = 0;
	coloring[n] = 1;
	q.push(1);
	q.push(n);
	while(!q.empty()){
		int here = q.front();
		q.pop();
		for(int there : e[here]){
			if(coloring[there] == -1){
				q.push(there);
				coloring[there] = coloring[here];
				if(coloring[here] == 0)	b++;
				else w++;
			}
		}
	}
	if(b>w)	cout<<"Fennec";
	else	cout<<"Snuke";
	return 0;
}