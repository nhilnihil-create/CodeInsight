#include<bits/stdc++.h>
using namespace std;
typedef long long signed int ll;
int main(){
	ll a,b;
  	cin>>a>>b;
	if(a<=0 && b>=0) cout<<"Zero";
	else if(a>0 && b>0) cout<<"Positive";
	else if((b-a+1)%2==0) cout<<"Positive";
	else cout<<"Negative";
	return 0;
}
	