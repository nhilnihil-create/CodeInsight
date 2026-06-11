#include <iostream>
#include<vector>
#include<queue>
using namespace std;
void solve(vector<int> &d,vector<vector<int>> l,int k){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
	pair<int,int> p,p2;
	p.first=0;
	p.second=k;
	q.push(p);
//	vector<int> use(d.size(),1);
	d[k]=0;
	while(q.size()){
		p=q.top();
		q.pop();
		for(int i=0;i<l[p.second].size();i++){
			p2.first=p.first+1;
			p2.second=l[p.second][i];
			if(d[p2.second]==-1){
				d[p2.second]=p2.first;
				q.push(p2);
			}

		}

	}
}

int main() {
	int n;cin>>n;
	vector<int> a(n),b(n);
	vector<vector<int>> l(n,vector<int>(0));
	for(int i=0;i<n-1;i++){
		cin>>a[i]>>b[i];
		a[i]--;
		b[i]--;
		l[a[i]].push_back(b[i]);
		l[b[i]].push_back(a[i]);
	}

	vector<int> d1(n,-1),dn(n,-1);
	solve(d1,l,0);
	solve(dn,l,n-1);
	int a1=0;
	int an=0;
	for(int i=0;i<n;i++){
		if(d1[i]>dn[i]){
			an++;
		}else{
			a1++;
		}
	}
	if(a1>an){
		cout<<"Fennec"<<endl;
	}else{
		cout<<"Snuke"<<endl;
	}
	return 0;
}
