#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
//#include<numeric>
#include<functional>
#include<deque>
#include<queue>
#include<string>
#include<iostream>

using namespace std;
const int one = 1;
const int big = (one<<30);
typedef long long int llint;
vector<int> E[100010];

int is2sai(int ter){
	int i,j,kore,gk;
	map<int,int> isg;
	queue<pair<int,int>> que;
	//isg[ter]=0;
	que.push(make_pair(ter,0));
	while(!que.empty()){
		kore=que.front().first;
		gk=que.front().second;
		que.pop();
		if(isg.count(kore)>0){//あった
			if(isg[kore]==gk){continue;}
			else{return 1;}
		} else{
			isg[kore]=gk;
		}
		for(i=0;i<E[kore].size();i++){
			que.push(make_pair(E[kore][i],(gk+1)%2));
		}
	}
	return 0;
}
int main(void){
	int i,j,gen=0,N,M,a,b;
	llint Ko=0,ren=0,s2ren=0,ans=0;
	vector<int> go;
	vector<int> rAnk;//rankだとstlの何かとと被る
	vector<int> cheak;
	scanf("%d %d",&N,&M);
	for(i=0;i<N;i++){
		go.push_back(i);
		rAnk.push_back(0);
	}
	for(i=0;i<M;i++){
		scanf("%d %d",&a,&b);
		a--;b--;//0-begin化
		E[a].push_back(b);
		E[b].push_back(a);
		while(a!=go[a]){a=go[a];}//根にたどる
		while(b!=go[b]){b=go[b];}
		if(a==b){continue;}//同じ根なら無視する
		if(rAnk[a]<rAnk[b]){swap(a,b);}
		if(rAnk[a]==rAnk[b]){rAnk[a]++;}
		go[b]=a;
	}
	for(i=0;i<N;i++){
		if(i!=go[i]){ continue; }
		if(rAnk[i]==0){ Ko++; } else{cheak.push_back(i); }
	}
	for(i=0;i<cheak.size();i++){
		if(is2sai(cheak[i])==0){
			s2ren++;
		} else{
			ren++;
		}
	}
	ans=(2*N-Ko)*Ko;
	ans+=s2ren*s2ren;
	ans+=(s2ren+ren)*(s2ren+ren);
	printf("%lld\n",ans);
	/*
	printf("Ko=%d\n",Ko);
	printf("ren=%d\n",ren);
	printf("s2ren=%d\n",s2ren);
	*/
	return 0;

}