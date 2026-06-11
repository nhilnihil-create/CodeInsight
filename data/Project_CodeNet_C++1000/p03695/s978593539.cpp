#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#include <iomanip>
//cout << fixed << setprecision(20) << *** << endl;
#define rep(i,N) for(int i=0;i<(int)N;++i)
typedef long long ll;
using namespace std;
//ユークリッド
ll gcd(ll a,ll b){
	ll t;
	if(a<b){
		t=a;
		a=b;
		b=t;
	}
	if(a%b==0)return b;
	return gcd(b,a%b);
}
//階乗
ll Factorial(ll a){
	ll b=1;
	for(ll i=a;i>=1;i--){
		b=b*i;
	}
	return b;
}
//素数判定
bool prime(ll n){
	for(ll i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main()
{
	ll N,Over=0,color=0;
	vector<ll>V(8,0);
	cin>>N;
	rep(i,N){
		ll t;
		cin>>t;
		if(t<400)V[0]=1;
		else if(t<800&&t>=400)V[1]=1;
		else if(t<1200&&t>=800)V[2]=1;
		else if(t<1600&&t>=1200)V[3]=1;
		else if(t<2000&&t>=1600)V[4]=1;
		else if(t<2400&&t>=2000)V[5]=1;
		else if(t<2800&&t>=2400)V[6]=1;
		else if(t<3200&&t>=2800)V[7]=1;
		else Over++;
	}
	color=count(V.begin(),V.end(),1);
	if(color==0){
		cout<<"1 "<<Over<<endl;
	}
	else{
		cout<<color<<" "<<color+Over<<endl;
	}
}
