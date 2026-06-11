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

int s[300005];
queue<int> q1;
priority_queue<P,vector<P>,greater<P> > q2;

int main(){
	int n;
	int i,j,k;
	int a,b,c;
	bool s1=true;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		a--;
		s[a]=i+1;
		q2.push(make_pair(a,i+1));
	}
	while(!q2.empty()){
		a=q2.top().second,q2.pop();
		for(i=1;i<a;i++)q1.push(a);
	}
	for(i=0;i<n*n;i++){
		if(s[i]!=0){
			if(!q1.empty() && s[i]==q1.front()){s1=false;break;}
			for(j=s[i];j<n;j++)q1.push(s[i]);
			continue;
		}
		if(q1.empty()){
			s1=false;
			break;
		}
		s[i]=q1.front(),q1.pop();
	}
	print_Yes_No(s1);
	if(s1)array_show(s,n*n);
}
