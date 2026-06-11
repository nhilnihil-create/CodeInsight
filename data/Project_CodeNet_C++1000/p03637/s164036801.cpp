#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

int main(){
	int n,m[100001];
	cin>>n;
	int a=0,b=0;
	for(int i=0;i<n;i++){
		cin>>m[i];
		if(m[i]%2==0&&m[i]%4!=0) a++;
		if(m[i]%4==0) b++;
	}
	if(a==n) cout<<"Yes";
	else if(b>=n/2) cout<<"Yes";
	else if(a+b>=n-b) cout<<"Yes";
	else cout<<"No";
	return 0;
}