#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> odd,even,b;
	for(int i=1,a;i<=m;i++){
		cin>>a;
		if(a&1)
			odd.emplace_back(a);
		else
			even.emplace_back(a);
	}
	if(odd.size()>2){
		cout<<"Impossible"<<endl;
		return 0;
	}
	if(odd.size()>=1)
		b.emplace_back(odd[0]);
	for(int it:even)
		b.emplace_back(it);
	if(odd.size()>=2)
		b.emplace_back(odd[1]);
	for(int it:b)
		cout<<it<<' ';
	cout<<endl;
	if(b.size()==1&&b[0]==1){
		cout<<1<<endl<<1<<endl;
	}
	else if(b.size()==1){
		cout<<2<<endl;
		cout<<1<<' '<<b[0]-1<<endl;
	}
	else{
		b[0]++;
		if((--b.back())==0)
			b.pop_back();
		cout<<b.size()<<endl;
		for(int it:b)
			cout<<it<<' ';
		cout<<endl;
	}
	
}
