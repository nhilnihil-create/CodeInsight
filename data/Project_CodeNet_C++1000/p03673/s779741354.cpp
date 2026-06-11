#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int n,a[N];
int main(){
	cin>>n>>a[1];
	deque<int>q;
	q.push_back(a[1]);
	int pos=1;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(i%2==0) q.push_back(a[i]);
		else q.push_front(a[i]);
		pos=(pos==1)?q.size():1;
	}
	if(pos==1){
		while(!q.empty()){
			printf("%d ",q.front());
			q.pop_front();
		}
	}
	else {
		while(!q.empty()){
			printf("%d ",q.back());
			q.pop_back();
		}
	}
	return 0;
}