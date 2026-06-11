#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;

const int maxn = 1010;

int n,sum;
int a[maxn];

priority_queue<int,vector<int>,greater<int> > q;

ll read(){ ll s=0,f=1; char ch=getchar(); while(ch<'0' || ch>'9'){ if(ch=='-') f=-1; ch=getchar(); } while(ch>='0' && ch<='9'){ s=s*10+ch-'0'; ch=getchar(); } return s*f; }

int main(){
	sum=0;
	n=read();
	
	for(int i=1;i<=n;i++){
		a[i] = read();
		sum += a[i];
		if(a[i]%10!=0)
			q.push(a[i]);
	}
	
	int cnt=0;
	while(sum%10==0 && !q.empty()){
		sum-=q.top();
		q.pop();
	}
	
	if(sum%10==0){
		printf("0\n");
	}else{
		printf("%d\n",sum);	
	}

	return 0;
}