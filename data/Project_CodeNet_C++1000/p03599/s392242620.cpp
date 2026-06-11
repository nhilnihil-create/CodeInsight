#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5,M=2e4+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a,b) memset(a,b,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define il inline
int A,B,C,D,E,F,x,y;
double mx=-1;
int main(){
	cin>>A>>B>>C>>D>>E>>F;
	A*=100,B*=100;
	for(int a=0;a<=F/A;a++){
		for(int b=0;b<=(F-a*A)/B;b++){
			for(int c=0;c<=(F-a*A-b*B)/C;c++){
				for(int d=0;d<=(F-a*A-b*B-c*C)/D;d++){
					int w=a*A+b*B,s=c*C+d*D;
					if(s<=w/100*E&&w+s<=F){
						if(s*1.0/(w+s)>mx){
							mx=s*1.0/(w+s),x=w+s,y=s;
						}
					}
				}
			}
		}
	}
	printf("%d %d\n",x,y); 
	return 0;
}