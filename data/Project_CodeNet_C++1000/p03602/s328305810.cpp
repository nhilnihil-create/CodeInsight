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
#include<iomanip>
#include<tuple>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<int,pair<int,int> > PP;
typedef pair<LL,int> LP;
typedef tuple<int,int,int> T;
const int INF=1<<30;
const LL MAX=1e9+7;

void array_show(int *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
	for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void print_YES_NO(bool answer){cout<<(answer?"YES":"NO")<<endl;}
void print_Yes_No(bool answer){cout<<(answer?"Yes":"No")<<endl;}
void print_POSSIBLE_IMPOSSIBLE(bool answer){cout<<(answer?"POSSIBLE":"IMPOSSIBLE")<<endl;}

vector<P> path[305];
LL dis[305];
priority_queue<LP,vector<LP>,greater<LP> > q1;
priority_queue<T,vector<T>,greater<T> > q2;

int t[305][305];

void queue_clear(priority_queue<LP,vector<LP>,greater<LP> > &q){
   priority_queue<LP,vector<LP>,greater<LP> > empty;
   swap( q, empty );
}

LL dijk(int p,int q){
	LL a,b,c;
	int i,j,k;
	bool flag=false;
	memset(dis,-1,sizeof(dis));
	queue_clear(q1);
	q1.push(make_pair(0,p));
	while(!q1.empty()){
		a=q1.top().first,b=q1.top().second,q1.pop();
		if(dis[b]!=-1)continue;
		dis[b]=a;
		if(b==q){
			flag=true;
			break;
		}
		for(i=0;i<path[b].size();i++){
			if(dis[path[b][i].first]!=-1)continue;
			q1.push(make_pair(a+path[b][i].second,path[b][i].first));
		}
	}
	if(flag)return a;
	return -1;
}

int main(){
	int n;
	int i,j,k;
	LL a,b,c,d;
	bool flag=true;
	LL s=0;
	cin>>n;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>t[i][j];
			if(i<j)q2.push(make_tuple(t[i][j],i,j));
		}
	}
	while(!q2.empty()){
		tie(a,b,c)=q2.top(),q2.pop();
		d=dijk(b,c);
		if(d==-1 || d>t[b][c]){
			path[b].push_back(make_pair(c,t[b][c]));
			path[c].push_back(make_pair(b,t[b][c]));
			s+=t[b][c];
			
		}else if(t[b][c]<d){
			flag=false;
			break;
		}
	}
	if(flag){
		for(i=0;i<n;i++){
			dijk(i,-1);
			for(j=0;j<n;j++){
				if(t[i][j]!=dis[j]){
					flag=false;
					break;
				}
			}
		}
	}
	if(!flag)s=-1;
	cout<<s<<endl;
	
}
