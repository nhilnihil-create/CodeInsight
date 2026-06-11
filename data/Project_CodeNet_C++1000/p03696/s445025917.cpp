#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn = 101000;

int n,m,x;
int lt,rt,dis[maxn];
string S,S1,S2;

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	x=10000;
	n=read();
	cin>>S;
	
	for(int i=0;i<n;i++){
		if(S[i]=='('){
			++lt;
		}
		if(S[i]==')'){
			++rt;
		}
		dis[i]=lt-rt;
		x=min(x,dis[i]);
	}
	
//	for(int i=0;i<n;i++) printf("%d ",dis[i]); printf("\n");
	
	if(x>=0){ 
		cout<<S;
		for(int i=0;i<dis[n-1];i++){
			printf("%c",')');
		}
		printf("\n");
	}
	if(x<0){
		for(int i=0;i<(-1*x);i++) printf("%c",'(');
		cout<<S;
		for(int i=0;i<dis[n-1]-x;i++) printf("%c",')');
		printf("\n");
	}
	
	return 0;
}