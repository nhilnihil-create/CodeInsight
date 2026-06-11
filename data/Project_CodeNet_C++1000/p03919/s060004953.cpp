#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define elif else if
int a,b,d;
char c;
string aa[30][30];
signed main()
{
	cin>>a>>b;
	rep(i,a){
		rep(j,b){
			cin>>aa[i][j];
			if(aa[i][j]=="snuke"){
				c='A'+j;
				d=i+1;
			}
		}
	}
	cout<<c<<d;
}