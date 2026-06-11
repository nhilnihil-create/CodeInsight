#include <iostream>
using namespace std;
int a[1000][1000];
const int t=2927;
int main(int argc, char** argv) {
	int n,m,h,w,sum=0;
	cin >> n >> m >> h >> w;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			sum+=t,a[i][j]=t;
	for(int i=h;i<=n;i+=h)
		for(int j=w;j<=m;j+=w)
			a[i][j]=-t*h*w-1+t,sum+=a[i][j],sum-=t;
	if(sum<0)
	{
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}