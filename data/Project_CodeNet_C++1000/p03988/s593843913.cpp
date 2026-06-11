#include<bits/stdc++.h>
using namespace std;

void fail(){
	cout<<"Impossible"<<endl;
	exit(0);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	multiset<int> m;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		m.insert(x);
	}
	int x=*prev(m.end());
	for(int i=0;i<=x;i++){
		auto it=m.find(x-i/2);
		if(it==m.end())
			fail();
		m.erase(it);
	}
	if(m.size()==0||(*m.begin()>=1+(x+1)/2))
		cout<<"Possible"<<endl;
	else
		fail();
}


