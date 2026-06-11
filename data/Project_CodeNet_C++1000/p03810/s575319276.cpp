#include<iostream>
#include<algorithm>
using namespace std;
const int MAX=100005;
int n,a[MAX];
int winner,current;
int gcd(int x,int y)
{
	if(x%y==0) return y;
	else return gcd(y,x%y);
}
void change(int pistol)
{
	int temp;
	a[pistol]--;
	temp=a[1];
	for(int i=2;i<=n;++i){
		temp=gcd(temp,a[i]);
	}
	for(int i=1;i<=n;++i){
		a[i]/=temp;
	}
}
bool check()
{
	int even=0,odd=0,pistol=0;
	for(int i=1;i<=n;++i){
		if(a[i]%2==0) even++;
		else{
			odd++;
			if(a[i]!=1) pistol=i;	
		} 
	}
	if(even%2==1){
		winner=current;
		return true;
	}
	if(odd>=2){
		winner=1-current;
		return true;
	}
	if(odd==1&&pistol==0){
		winner=1-current;
		return true;
	}
	change(pistol);
	return false;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;++i) cin>>a[i];
	current=1;
	while(!check()) current=1-current;
	if(winner==1) cout<<"First"<<endl;
	else cout<<"Second"<<endl;
	return 0;
}