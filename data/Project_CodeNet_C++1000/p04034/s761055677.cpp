#include<iostream>
#include<map>
#include<vector>
 
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	vector<bool> red(n+1,false);
	vector<int> balls(n+1,1);
	red[1]=true;
	for(int i=0;i<m;++i){
		int from,to;
		cin>>from>>to;
		if(red[from])
			red[to]=true;
		--balls[from];
		++balls[to];
		if(balls[from]==0)
			red[from]=false;
	}
	int cnt=0;
	for(int i=1;i<=n;++i)
		if(red[i])
			++cnt;
	cout<<cnt<<"\n";
	return 0;
}
