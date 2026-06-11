#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;
typedef long long int LL;
vector<int> path[100005];
int num[100005];
queue<pair<int,int> > q1;

int check(int a){
	int i,j,k;
	int s=0;
	int b,c;
	q1.push(make_pair(a,1));
	while(!q1.empty()){
		a=q1.front().first,b=q1.front().second,q1.pop();
		if(num[a]!=0){
			if(num[a]!=b)s=1;
			continue;
		}
		num[a]=b;
		for(i=0;i<path[a].size();i++){
			q1.push(make_pair(path[a][i],3-b));
		}
	}
	return s;
}

int main(){
	LL n,m;
	int i,j,k;
	int a,b,c;
	LL t[5]={0};
	LL s=0;
	cin>>n>>m;
	for(i=0;i<m;i++){
		cin>>a>>b;
		a--,b--;
		path[a].push_back(b);
		path[b].push_back(a);
	}
	for(i=0;i<n;i++){
		if(num[i]==0){
			if(path[i].size()==0)t[2]++;
			else t[check(i)]++;
		}
	}
	s=(t[0]+t[1])*(t[0]+t[1]);
	s+=t[0]*t[0];
	s+=n*n-(n-t[2])*(n-t[2]);
	cout<<s<<endl;
	return 0;
}

