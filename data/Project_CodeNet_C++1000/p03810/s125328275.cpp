#include <bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int n;
int a[200000];

bool C(){
	int cnt=0;
	rep(i,n){
		if(a[i]%2==0)cnt++;
	}
	if(cnt%2==1)return true;
	return false;
}
int main(){
	cin>>n;
	rep(i,n){
		scanf("%d",&a[i]);
	}
	int turn=0;
	while(1){
		if(C()){
			puts(turn==0?"First":"Second");
			return 0;
		}
		int cnt=0;
		rep(i,n){
			if(a[i]%2==1)cnt++;
		}
		if(cnt!=1){
			puts(turn==0?"Second":"First");
			return 0;
		}
		rep(i,n){
			if(a[i]%2==1){
				if(a[i]==1){puts(turn==0?"Second":"First");return 0;}
				a[i]--;
			}
		}
		int g=a[0];
		rep(i,n)g=__gcd(g,a[i]);
		rep(i,n)a[i]/=g;
		turn=!turn;
	}
}