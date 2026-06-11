#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> xd;
	int suma=0;
	for (int i=0; i<n; i++){
		int in;
		cin>>in;
		suma+=in;
		xd.push_back(in);
	}
	vector<int> resp;
	int m;
	cin>>m;
	for (int i=0; i<m; i++){
		int p, x;
		cin>>p; cin>>x;
		p--;
		int aux=suma-xd[p]+x;
		resp.push_back(aux);
	}
	for (auto a: resp){
		cout<<a<<endl;
	}
	return 0;
}