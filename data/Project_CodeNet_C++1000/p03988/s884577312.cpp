#include<iostream>
using namespace std;
int t[105];
int main(){
	int n;
	int a,b,c;
	int i,j,k;
	bool s=true;
	cin>>n;
	for(c=0,i=0;i<n;i++){
		cin>>a;
		t[a]++;
		if(c<a)c=a;
	}
	for(i=c;i>(c+1)/2;i--){
		if(t[i]<2)s=false;
	}
	if(c%2==0 && t[c/2]!=1)s=false;
	if(c%2==1 && t[(c+1)/2]!=2)s=false;
	if(s)cout<<"Possible"<<endl;
	else cout<<"Impossible"<<endl;
	return 0;
}
	
	
