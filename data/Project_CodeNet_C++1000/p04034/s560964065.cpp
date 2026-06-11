#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,m,x,y,res=0;
	cin>>n>>m;
	int num[100001]={0},ball_num[100001]={0};
	num[1]=1;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		ball_num[x]--;
		ball_num[y]++;
		if(num[x]==1){
			num[y]=1;			
		}
		if(ball_num[x]==-1){
			num[x]=0;
		}
	}
	for(int i=1;i<=n;i++){
		if(num[i]==1)
			res++;
	}
	cout<<res<<endl;
	return 0;
}