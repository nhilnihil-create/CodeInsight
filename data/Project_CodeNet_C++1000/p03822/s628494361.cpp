#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
typedef pair<LL,int> LP;
const int INF=1<<30;


void array_show(int *a,int n){
	for(int i=0;i<n;i++)printf("%d%c",a[i],(i!=n-1?' ':'\n'));
}
void array_show(LL *a,int n){
	for(int i=0;i<n;i++)printf("%lld%c",a[i],(i!=n-1?' ':'\n'));
}

vector<int> win[100005];
priority_queue<int> q1;
int s[100005];

int check(int a){
	int b,c;
	if(s[a]!=-1)return s[a];
	if(win[a].size()==0){
		s[a]=0;
		return 0;
	}
	for(int i=0;i<win[a].size();i++){
		check(win[a][i]);
	}
	for(int i=0;i<win[a].size();i++){
		q1.push(check(win[a][i]));
	}
	b=0;
	for(int i=0;i<win[a].size();i++){
		c=i+q1.top()+1,q1.pop();
		b=max(b,c);
	}
	s[a]=b;
	return b;
}

int main(){
	int n;
	int i,j,k;
	int a,b,c;
	memset(s,-1,sizeof(s));
	cin>>n;
	for(i=1;i<n;i++){
		cin>>a;
		win[a-1].push_back(i);
	}
	cout<<check(0)<<endl;
	return 0;
}
