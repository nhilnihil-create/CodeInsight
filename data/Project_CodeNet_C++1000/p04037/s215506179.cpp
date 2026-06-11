#include<bits/stdc++.h>
using namespace std;

int a[100001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,greater<int>());
	int col=0;
	while(col+1<n&&a[col+1]>col+1)
		col++;
	int u=0,r=0;
	u=a[col]-col;
	while(col+r<n&&a[col+r]>col)
		r++;
	if(!(u&1)||!(r&1))
		cout<<"First"<<endl;
	else
		cout<<"Second"<<endl;

}
