#include<bits/stdc++.h>
using namespace std;

int n,m,a[110],p;
vector<int>v;
int main(){
	cin>>n>>m;
	if (n==1) return 0*printf("1\n1\n1");
	for (int i=1;i<=m;++i) {
		cin>>a[i]; if (a[i]&1) v.push_back(i);
	}
	if (v.size()){
		swap(a[1],a[v[0]]);
		if (v.size()>1){
			swap(a[m],a[v[1]]);
			if (v.size()>2) return 0*puts("Impossible");
		}
	}
	for (int i=1;i<=m;++i) printf("%d ",a[i]);
	if (m==1) return 0*printf("\n2\n1 %d",n-1);
	p=--a[1]?1:2, ++a[m];
	printf("\n%d\n",m-p+1);
	for (int i=p;i<=m;++i) printf("%d ",a[i]);
}