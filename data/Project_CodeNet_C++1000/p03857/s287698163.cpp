#include "bits/stdc++.h"
using namespace std;

const long long int maxKL=(1e5)*2+1;

vector<int> kv(maxKL,0);
vector<int> lv(maxKL,0);
vector<int> Gk[maxKL];
vector<int> Gl[maxKL];
int np;

int dfsk(int p){
	for(int i=0;i<Gk[p].size();i++){
		if(kv[Gk[p][i]]==0){
			kv[Gk[p][i]]=np;
			dfsk(Gk[p][i]);
		}
	}
	return 0;
}

int dfsl(int p){
	for(int i=0;i<Gl[p].size();i++){
		if(lv[Gl[p][i]]==0){
			lv[Gl[p][i]]=np;
			dfsl(Gl[p][i]);
		}
	}
	
	return 0;
}

int main(){
	int n,k,l;
	cin>>n>>k>>l;
	int a,b;
	for(int i=0;i<k;i++){
		cin>>a>>b;
		a--;
		b--;
		Gk[a].push_back(b);
		Gk[b].push_back(a);
	}
	for(int i=0;i<l;i++){
		cin>>a>>b;
		a--;
		b--;
		Gl[a].push_back(b);
		Gl[b].push_back(a);
	}
	np=1;
	for(int i=0;i<n;i++){
		if(kv[i]==0){
			kv[i]=np;
			dfsk(i);
			np++;
		}
	}
	np=1;
	for(int i=0;i<n;i++){
		if(lv[i]==0){
			lv[i]=np;
			dfsl(i);
			np++;
		}
	}
	
	map<pair<int,int>,int > mp;
	for(int i=0;i<n;i++)mp[make_pair(kv[i],lv[i])]++;
	for(int i=0;i<n;i++){
		if(i)cout<<" ";
		cout<<mp[make_pair(kv[i],lv[i])];
	}
	cout<<endl;
	
	
	/*
	for(int i=0;i<n;i++){
		cout<<"k"<<i+1<<" "<<kv[i]<<endl;
	}
	for(int i=0;i<n;i++){
		cout<<"l"<<i+1<<" "<<lv[i]<<endl;
	}
	*/
	
	
	return 0;
}