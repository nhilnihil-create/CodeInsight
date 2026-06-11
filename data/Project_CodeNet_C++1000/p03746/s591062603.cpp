#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> sol1;
vector<int> sol2;
void dfs(int indx1,int indx2,vector<vector<int> > *g,vector<bool> *bio){
	//cout<<indx1+1<<" "<<indx2+1<<endl;
	if(indx1== -1 && indx2== -1) return;
	if(indx1>-1){
		(*bio)[indx1]=true;
	}
	if(indx2>-1){
		(*bio)[indx2]=true;
	}
	int nindx1=-1;
	int nindx2=-1;
	if(indx1 != -1){
	
		for(int i=0;i<(*g)[indx1].size();i++){
			if((*bio)[(*g)[indx1][i]]) continue;
			nindx1=(*g)[indx1][i];
		}
		sol1.push_back(indx1);
		(*bio)[indx1]=true;
	}
	if(indx2 != -1){
	
		for(int i=0;i<(*g)[indx2].size();i++){
			if((*bio)[(*g)[indx2][i]]  || (*g)[indx2][i]==nindx1) continue;
			nindx2=(*g)[indx2][i];
		}
		sol2.push_back(indx2);
		(*bio)[indx2]=true;
	}
	dfs(nindx1,nindx2,g,bio);
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int> > graf(n);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	vector<bool> bio(n,false);
	bio[0]=true;
	bio[graf[0][0]]=true;
	dfs(0,graf[0][0],&graf,&bio);
	reverse(sol1.begin(),sol1.end());
	//reverse(sol2.begin(),sol2.end());
	cout<<sol1.size()+sol2.size()<<endl;
	for(int i=0;i<sol1.size();i++) cout<<sol1[i]+1<<" ";
	for(int i=0;i<sol2.size();i++) cout<<sol2[i]+1<<" ";
}