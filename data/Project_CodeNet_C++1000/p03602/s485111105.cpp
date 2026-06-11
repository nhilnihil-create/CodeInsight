#include<bits/stdc++.h>
using namespace std;
const int N=301;
bool b[N][N];
long long f[N][N],ans;
int n;
int main(){
	scanf("%d",&n);
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
	scanf("%lld",&f[i][j]);
	for (int k=n; k>=1; k--)
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
	if (i!=k&&k!=j&&i!=j){
		if (f[i][k]+f[k][j]<f[i][j]){
			puts("-1");
			return 0;
		}
		else if (f[i][k]+f[k][j]==f[i][j]) b[i][j]=1;
	}
	for (int i=1; i<=n; i++)
	for (int j=1; j<=n; j++)
	if (!b[i][j]) ans+=f[i][j];
	printf("%lld",ans>>1);
}