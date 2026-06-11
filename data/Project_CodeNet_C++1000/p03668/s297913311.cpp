#include <iostream>
#include <vector>
using namespace std;

vector<int> G[100000];

int calc(int v,int par){
	int g = 0;
	for(int to : G[v]){
		if(to != par) g ^= calc(to,v);
	}
	if(par != -1) g++;
	return g;
}

int main(){
	int n;
	cin >> n;
	for(int i = 0;i < n - 1;i++){
		int a,b;
		cin >> a >> b; a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	if(calc(0,-1)) cout << "Alice" << endl;
	else cout << "Bob" << endl;
	return 0;
}