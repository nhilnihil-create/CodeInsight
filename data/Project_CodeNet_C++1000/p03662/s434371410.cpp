#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,P> P2;
const ll inf=100000000000000001;
vector<int> v[100001];

int main() {
	int n;
	cin>>n;
	for(int i=0;i<n-1;++i){
		int a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<P> que;
	int dp[100001]={};
	que.push(P(1,1));
	while(!que.empty()){
		P p1=que.front();que.pop();
		int to=p1.first;
		int cost=p1.second;
		if(dp[to]>0)continue;
		dp[to]=cost;
		for(auto it:v[to])que.push(P(it,cost+1));
	}
	int f=(dp[n]-1)/2+1;
	int s=n;
	for(int i=dp[n];i>f;--i){
		for(auto it:v[s]){
			if(dp[it]==i-1&&dp[it]>=f+1){
				s=it;
				break;
			}
		}
	}
	int t=0;
	que.push(P(s,1));
	while(!que.empty()){
		P p1=que.front();que.pop();
		int to=p1.first;
		int cost=p1.second;
		t++;
		for(auto it:v[to]){
			if(dp[it]>dp[to])que.push(P(it,cost+1));
		}
	}
//	cout<<t;
	if(t<n-t){
		cout<<"Fennec"<<endl;
	}else{
		cout<<"Snuke"<<endl;
	}
	return 0;
}
