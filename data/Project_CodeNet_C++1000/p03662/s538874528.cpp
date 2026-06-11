#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<cstdio>
#include<algorithm>
#define LL long long
#define INF 1ll<<60
using namespace std;
const int N=2e5+100;
const int M=4e5+100;
const int mod=1e9+7;
int head[N],Next[M],ver[N],tot;
void add(int x,int y) {
    ver[++tot]=y;
    Next[tot]=head[x];
    head[x]=tot;
}
int vis[N];
int n,flag;

int tmp[N],kk=0;
void dfs(int x){
	if(x==n){
			tmp[++kk]=x;
			return ;
		}
	for(int i=head[x];i;i=Next[i]){
		
		int y=ver[i];
		if(vis[y])continue;
		vis[y]=1;
		
		dfs(y);
		if(kk){
			tmp[++kk]=x;
			return ;	
		}
	}
}
int mark[N];
int cal(int x){
	int cnt=0;
	for(int i=head[x];i;i=Next[i]){
		
		int y=ver[i];
		
		if(mark[y]||vis[y]==flag)continue;//cout<<y<<".."<<" "<<vis[y]<<" "<<flag<<endl;
		mark[y]=1;
		cnt+=cal(y);
	}
	return cnt+1;
	
}
int main() {

    while(cin>>n) {
        tot=1;
        int num1=0,num2=0;
        memset(head,0,sizeof(head));
        memset(Next,0,sizeof(Next));
        memset(ver,0,sizeof(ver));
        memset(vis,0,sizeof(vis));
        memset(mark,0,sizeof(mark));
        tmp[0]=0;
        kk=0;
        int x,y;
        for(int i=1; i<n; i++) {
            cin>> x >> y;
            add(x,y);
            add(y,x);
        }
		vis[1]=1;
        dfs(1);
        
        memset(vis,0,sizeof(vis));
        int l=1,r=kk;
        while(l<=r){
        	int x=tmp[l];
        	int y=tmp[r];
        	if(vis[y]==0)vis[y]=1;
        	if(vis[x]==0)vis[x]=2;
        	l++;r--;
  	
		}
//		for(int i=1;i<=n;i++)cout<<vis[i]<<" ";
//		cout<<endl;
		flag=2;
		mark[1]=1;
		num1=cal(1);
		
		flag=1;
		memset(mark,0,sizeof(mark));
		mark[n]=1;
		num2=cal(n);
		
		
		//cout<<num1<<" "<<num2<<endl;
        if(num1>num2){
        	cout<<"Fennec"<<endl; 
        	
		}else{
			cout<<"Snuke"<<endl;
			
		}

    }
    return 0;

}
