#include<bits/stdc++.h>
using namespace std;

int p[100001][17],a[100001];
int A,B;

bool check(int x){
	int tmp=B,stp=0;
	while(x){
		if(x&1)	tmp=p[tmp][stp];
		stp++;
		x>>=1;
	}
	return tmp<=A;

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,L,k;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int tmp=n;
	cin>>L>>k;
	for(int i=n;i>=1;i--){
		while(tmp>0&&a[i]-a[tmp]<=L)
			tmp--;
		p[i][0]=tmp+1;
	}
	for(int j=1;j<=16;j++)
		for(int i=1;i<=n;i++)
			p[i][j]=p[p[i][j-1]][j-1];
	for(int i=1;i<=k;i++){
		cin>>A>>B;
		if(A>B)	swap(A,B);
		int l=0,r=100000;
		while(l<r){
			int mid=(l+r)/2;
			if(check(mid))
				r=mid;
			else
				l=mid+1;
		}
		cout<<l<<'\n';
	}
}
