#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
	
ll a,b;
cin>>a>>b;

if(a<0&&b>0)cout<<"Zero";
else if(a<0&&b<0){
	if((b-a+1)%2)cout<<"Negative";
	else
	cout<<"Positive";
}
else if(a>0)cout<<"Positive";
}