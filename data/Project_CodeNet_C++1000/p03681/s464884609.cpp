#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(i=a;i<=b;i++)
#define rep2(i,a,b,c) for(i=a;i<=b;i+=c)
#define maxn 100000
#define ll long long
ll mod=(ll)1000000007;
ll fact[maxn+1];

void prekom(){
	fact[0]=1;
	int i;
	rep(i,1,maxn){
		fact[i]=(fact[i-1]*(ll)i)%mod;
	}
}

int main(){
	prekom();
	int N,M;
	cin>>N>>M;
	if(abs(N-M) > 1){
		cout<<"0\n";
	}
	else if(N==M){
		cout<<(fact[N]*fact[M]*(ll)2)%mod<<"\n";
	}
	else{
		cout<<(fact[N]*fact[M])%mod<<"\n";
	}
}
