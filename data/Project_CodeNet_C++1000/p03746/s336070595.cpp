#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph(111111);

int main(){
	int N,M;
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int A,B;
		cin >> A >> B;
		A--;
		B--;
		graph[A].push_back(B);
		graph[B].push_back(A);
	}
	vector<bool> used(N,false);
	deque<int> deq;
	deq.push_back(0);
	deq.push_back(graph[0][0]);
	used[0]=used[graph[0][0]]=true;
	int X=2;
	
	bool flag=false;
	while(1){
		if(!flag){
			int& x=deq.front();
			bool f=true;
			for(auto t:graph[x]){
				if(!used[t]){
					deq.push_front(t);
					X++;
					used[t]=true;
					f=false;
					break;
				}
			}
			if(f)flag=true;
			if(!flag)continue;
		}
		int& x=deq.back();
		bool ff=true;
		for(auto t:graph[x]){
			if(!used[t]){
				deq.push_back(t);
				X++;
				used[t]=true;
				ff=false;
				break;
			}	
		}
		if(ff){
			cout << X << endl;
				while(!deq.empty()){
					int& x=deq.front();
					cout << x+1;
					deq.pop_front();
					if(deq.empty())cout << endl;
					else cout << " ";
				}
			return 0;
		}
	}
	return 0;
}