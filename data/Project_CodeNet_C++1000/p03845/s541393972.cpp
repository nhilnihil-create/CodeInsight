#include <bits/stdc++.h>
using namespace std;
int main(){
	int n = 0, N;cin>>N;
	int *tp = new int[N];
	while(n < N){
		cin>>tp[n];n++;
	}
	int M;cin>>M;
	int m = M, a, b;
	queue < pair<int,int> > q;
	while(M--){
		cin>>a>>b;
		q.push({a,b});
	}
	int suma = 0, diferencia = 0;
	for(int i = 0; i < N; i++)suma+=tp[i];
	pair<int,int> p;
	while(q.size()){
		p = q.front();
		diferencia = p.second - tp[p.first-1];
		q.pop();
		cout<<suma+diferencia<<endl;
	}
}