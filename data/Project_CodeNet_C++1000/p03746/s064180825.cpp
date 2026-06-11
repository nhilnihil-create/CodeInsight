
#include <iostream>
#include<vector>
using namespace std;

int main() {
	int n,m;cin>>n>>m;
	vector<int> a(m),b(m);
	vector<vector<int>> v(n,vector<int>(0));
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i];
		a[i]--;
		b[i]--;
		v[a[i]].push_back(b[i]);
		v[b[i]].push_back(a[i]);
	}
	vector<int> used(n,0);
	used[a[0]]=1;
	used[b[0]]=1;
	vector<vector<int>> l(2,vector<int>(0));
	for(int i=0;i<2;i++){
		if(i==0){
		l[0].push_back(a[0]);
		}else{
			l[1].push_back(b[0]);
		}
		while(1){
			int flag=0;
			for(int j=0;j<v[l[i].back()].size();j++){
				if(used[v[l[i].back()][j]]==0){
					used[v[l[i].back()][j]]=1;
					l[i].push_back(v[l[i].back()][j]);
					flag=1;
					break;
				}
			}
			if(flag==0)break;
		}
	}
	cout<<l[0].size()+l[1].size()<<endl;
	for(int i=l[1].size()-1;i>=0;i--){
		cout<<l[1][i]+1<<' ';
	}
	for(int i=0;i<l[0].size();i++){
		cout<<l[0][i]+1<<' ';
	}

	cout<<endl;
	return 0;
}
