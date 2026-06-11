#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

/*
int judge(long long ans_a,long long ans_t,int a,int t){
	//long long www = w_gcd(ans_a,ans_t);
	long long aa = ans_a / www;
	long long at = ans_t / www;
	if(aa*t > at*a) return 1;
	else return 2;
}
*/
int main(void)
{
	int n; cin>>n;
	long long t[n],a[n]; for(int i = 0; i < n; i++) cin>>t[i]>>a[i];
	long long ans_t = t[0], ans_a = a[0];
	for(int i = 1;i < n; i++){
		//if(judge(ans_a,ans_t,a[i],t[i]) == 1){}
		if(a[i-1]*t[i] > t[i-1]*a[i]){
			while(ans_a % a[i] != 0)ans_a++;
			ans_t = ans_a/a[i];
			ans_t = ans_t*t[i];
		}
		else{
			while(ans_t % t[i] != 0) ans_t++;
			ans_a = ans_t/t[i];
			ans_a = ans_a*a[i];
		}
		//cout<<"ans_t = "<<ans_t<<", ans_a = "<<ans_a<<endl;
	}
	cout<<ans_t+ans_a<<endl;
	return 0;
}

