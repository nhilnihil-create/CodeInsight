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


int seg_tree[1<<18],seg_N;
const int seg_init_num=1<<30;

void seg_init(int n){
	int i;
	for(i=0;(1<<i)<n;i++);
	seg_N=(1<<i)-1;
}

int seg_search(int n,bool first=true){
	if(first)n+=seg_N;
	if(n==0)return seg_tree[0];
	return seg_tree[n]+seg_search((n-1)/2,false);
}

void seg_set(int a,int b,int n=0,int r=0,int l=seg_N){
	if(l<a || b<r)return;
	if(a<=r && l<=b){
		seg_tree[n]++;
		return;
	}
	seg_set(a,b,n*2+1,r,(r+l)/2);
	seg_set(a,b,n*2+2,(r+l)/2+1,l);
}

void array_show(int *a,int n){
	for(int i=0;i<n;i++)printf("%d%c",a[i],(i!=n-1?' ':'\n'));
}
void array_show(LL *a,int n){
	for(int i=0;i<n;i++)printf("%lld%c",a[i],(i!=n-1?' ':'\n'));
}

int t[300005][2];
int s[100005];
priority_queue<P,vector<P>,greater<P> > q1;

int main(){
	int n,m;
	int i,j,k;
	int a,b,c;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>t[i][0]>>t[i][1];
		a=t[i][1]-t[i][0];
		s[a]++;
		q1.push(make_pair(a,i));
	}
	for(i=m-1;i>=0;i--){
		s[i]+=s[i+1];
	}
	seg_init(m+1);
	for(i=0;i<m;i++){
		while(!q1.empty() && q1.top().first==i-1){
			a=q1.top().second,q1.pop();
			seg_set(t[a][0],t[a][1]);
		}
		for(j=0;j<=m;j+=i+1){
			s[i]+=seg_search(j);
		}
	}
	for(i=0;i<m;i++){
		cout<<s[i]<<endl;
	}
}
