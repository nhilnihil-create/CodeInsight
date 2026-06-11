#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
#define LL long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=2e5+100;
int arr[N];
char str[N],res[N];
bool solve(int n){
	bool flag=0;
	for(int i=1;i<=n;i++){
			int l=i-1,r=i+1;
			if(l==0)l=n;
			if(r==n+1)r=1;
			
			bool tmp=(str[i]=='o');
			if(res[i]=='W')tmp=!tmp;
			if(tmp){
				if(res[l]!='0'&&res[r]!='0'&&res[r]!=res[l]){
					flag=1;
					break;
				}else if(res[l]!='0'&&res[r]!='0'&&res[r]==res[l]){
					continue;
					
				}else{
					if(res[r]=='0')res[r]=res[l];
					else if(res[l]=='0')res[l]=res[r];
					else res[r]=res[l]='S';
				}
			}else{
				if(res[r]!='0'&&res[l]!='0'&&res[r]==res[l]){
					flag=1;
					break;
				}else if(res[r]!='0'&&res[l]!='0'&&res[r]!=res[l]){
					continue;
				}else{
					if(res[r]=='0')res[r]=(res[l]=='S'?'W':'S');
					else if(res[l]=='0')res[l]=(res[r]=='S'?'W':'S');
					else res[l]='S',res[r]='W';	
				}
			}
		}
	return flag;
}
int main() {
	int n;
	while(scanf("%d",&n)!=EOF){
		
		scanf("%s",str+1);
		bool flag=0;
		memset(res,'0',sizeof(res));
		res[1]='S';
		res[2]='W';
		flag=solve(n);
		if(!flag){
			goto fun;
		}
		
		memset(res,'0',sizeof(res));
		res[1]='S';
		res[2]='S';
		flag=solve(n);
	
		if(!flag){
			goto fun;
		}
		
		memset(res,'0',sizeof(res));
		res[1]='W';
		res[2]='W';
		flag=solve(n);
		if(!flag){
			goto fun;
		}
		
		memset(res,'0',sizeof(res));
		res[1]='W';
		res[2]='S';
		flag=solve(n);
		if(!flag){
			goto fun;
		}
		
		fun:
		if(flag)printf("-1\n");
		else{
			for(int i=1;i<=n;i++)printf("%c",res[i]);
			printf("\n");
		} 	
	}

	return 0;
}
