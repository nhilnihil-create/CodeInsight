#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

bool a[100010];
	ll n;
	string s;	bool ch=true;
void dep(){
		for(int i=1;i<n-1;i++){
		bool now;
		if(s[i]=='o'){
			now =true;
		}
		else{
			now=false;
		}
		if((now+a[i]+a[i-1])%2){
			a[i+1]=true;
		}
		else{
			a[i+1]=false;
		}
	}
	for(int i=n;i<n+2;i++){
		a[i]=a[i-n];
	}
	for(int i=1;i<=n;i++){
		bool now;
		if(s[i]=='o'){
			now =true;
		}
		else{
			now=false;
		}
		if((a[i-1]+a[i]+a[i+1])%2!=now){
			ch=false;
		}
	}
}

int main() {

	cin>>n>>s;
	s+=s;

	a[0]=true;a[1]=true;
	dep();

	if(ch==false){
		ch=true;
		a[0]=false;a[1]=true;
		dep();
	}
	
	if(ch==false){
		ch=true;
		a[0]=true;a[1]=false;
		dep();
	}

	if(ch==false){
		ch=true;
		a[0]=false;a[1]=false;
		dep();
	}
	
	if(ch==true){
	for(int i=0;i<n;i++){
		if(a[i]){
			cout << 'S';
		}
		else{
			cout << 'W';
		}
	}
	}
	else{
		cout << -1;
	}
	return 0;
}