#include<bits/stdc++.h>
using namespace std;
long long q,h,s,d,n,mina,minb;
int main(){
	cin>>q>>h>>s>>d;
	cin>>n; 
	mina=min(q*4,h*2);
	mina=min(mina,s);
	minb=min(mina*2,d);
	cout<<n/2*minb+n%2*mina<<endl;	
}