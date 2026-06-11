#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<bool > hr(n);
	vector<int >ct(n,1);
	hr[0]=true;
	for(int i=0,from,to;i<m;i++){
		cin>>from>>to;
		from--;
		to--;
		if(hr[from]){
			hr[to]=true;
			ct[from]--;
			ct[to]++;
			if(ct[from]==0)hr[from]=false;
		}
		else{
			ct[from]--;
			ct[to]++;
		}
	}
	int fina=0;
	for(int i=0;i<n;i++)if(hr[i])fina++;
	cout<<fina<<'\n';
}