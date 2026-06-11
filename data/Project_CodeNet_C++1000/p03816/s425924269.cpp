#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	map<int,int>m;
	map<int,int>::iterator it;
	while(n--){
		int a;
		cin>>a;
		it = m.find(a);
		if(it!=m.end()) it->second+=1;
		else m.insert(make_pair(a,1));
	}
	if(m.size()%2) cout<<m.size();
	else cout<<m.size()-1;
}