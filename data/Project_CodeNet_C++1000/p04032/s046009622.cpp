#include<iostream>
#include<string>
using namespace std;

int beki(int a,int b){
	int ans=1;
	for(int i=0;i<b;i++){
		ans=ans*a;
	}
	return ans;
}
int main(){
string a;
cin>>a;
int t=a.length();
for(int i=0;i<t-2;i++){
if(a[i]==a[i+1]){cout<<i+1<<" "<<i+2<<endl;return 0;}
if(a[i]==a[i+2]){cout<<i+1<<" "<<i+3<<endl;return 0;}
}
if(a[t-2]==a[t-1]){cout<<t-1<<" "<<t<<endl;return 0;}
cout<<-1<<" "<<-1<<endl;
return 0;
}