#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100005];
int main(){
	cin>>n;for(int i=1;i<=n;i++){cin>>a[i]>>b[i];}
  	auto m = max_element(a+1,a+n+1);
  	cout<<(*m)+b[m-a];
}