#include<iostream>
#include<cmath>
using namespace std;
typedef long long int LL;
LL t[3][100005];
int main(){
	LL a,b,c;
	int n,m;
	int i,j,k;
	LL s=0;
	cin>>n>>m;
	for(i=0;i<n;i++,a=b){
		cin>>b;
		if(i==0)continue;
		if(a<b)c=b-a,t[2][0]+=c;
		else c=b+m-a,t[2][0]+=b+1,t[1][0]--;
		t[0][a]--,t[0][b-1]+=c,t[0][b]-=c-1;
	}
	for(i=1;i<=2;i++){
		for(j=1;j<=m;j++){
			t[i][j]=t[i][j-1]+t[i-1][j-1];
		}
	}
	for(i=1,s=t[2][1];i<=m;i++){
		if(s>t[2][i])s=t[2][i];
	}
	cout<<s<<endl;
	return 0;
}
