#include<bits/stdc++.h>
using namespace std;

int ma[100010];
int a[100010];
vector <int> v;
int n,m;

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=n-1;i>=0;i--) ma[i]=max(ma[i+1],a[i]);
	for(int i=0;i<n;i++)
		v.push_back(ma[i]-a[i]);
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	int maxm=v[0];
	int ans=0;
	for(int i=0;i<v.size();i++)
		if(v[i]==maxm) ans++;
	printf("%d",ans);
	return 0;
}