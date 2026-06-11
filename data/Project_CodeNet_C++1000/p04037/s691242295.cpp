#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
typedef long long ll;
int a[N],n;
bool cmp(const int &a,const int &b){return a>b;}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int X;
	int th;
	for(int i=0;i<n;i++){
		int H=i,W=a[i+1]-1;
		if(H<=W)X=H,th=(a[i+1]-1-H)%2;
	}
	int tu=0;
	for(int i=X+1;i<n;i++){
		if(a[i+1]-1==X)tu^=1;
	}
	if(tu||th)cout<<"First"<<endl;
	else cout<<"Second"<<endl;
}