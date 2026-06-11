#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=1e6+5,inf=0x3f3f3f3f,mod=1e9+7;
#define mst(a) memset(a,0,sizeof a)
#define lx x<<1
#define rx x<<1|1
#define reg register
#define PII pair<int,int>
#define fi first 
#define se second
int main(){
	string a,b,c;
	cin>>a>>b>>c;
	int i=0,j=0,k=0,id=0;
	int x=a.size(),y=b.size(),z=c.size();
	while(1){
		if(i==x&&!id) return puts("A"),0;
		else if(j==y&&id==1) return puts("B"),0;
		else if(k==z&&id==2) return puts("C"),0;
		if(!id) id=a[i]-'a',i++;
		else if(id==1) id=b[j]-'a',j++;
		else if(id==2) id=c[k]-'a',k++;
	}
	return 0;
}
