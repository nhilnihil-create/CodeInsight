#include<iostream>
#include<vector>
using namespace std;
typedef long long int ll;
int main(void){
ll n;
cin>>n;
//for(ll n=4;n<=1000;n++){
if(n<=2){
	cout<<n<<endl;
	return 0;
}
if(n==3){
	cout<<1<<endl;
	cout<<2<<endl;
	return 0;
}
ll ans,no,sum=0;
for(ll i=1;i<=n;i++){
	 sum+=i;
	if(sum>=n){
		ans=i;
		no=sum-n;
		break;
	}
}
	//cout<<no<<endl;
int t=0;
for(ll i=1;i<=ans;i++){
	if(i!=no){
	cout<<i<<endl;
//t+=i;
	}
}
//if(t!=n)cout<<n<<endl;
//}
	return 0;
}