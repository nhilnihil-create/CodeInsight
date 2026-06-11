#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

typedef long long ll;
const ll mod=1e9+7;
const ll MAXN=1e3+10;

int main()//所有的循环已改正 
{
	int n;
	cin>>n;
	char s1[MAXN],s2[MAXN];
	int vis[MAXN]={0};
	ll ans=0;
	cin>>s1>>s2;
	for(int i=0;i<n;i++){
		if(i==0){
			if(s1[i]==s2[i]){
				ans=3;
				vis[i]=1;
			}
			else {
				ans=6;
				vis[i+1]=2;
				i++;
			}
		}
		else {
			if(s1[i]==s2[i]){
				if(vis[i-1]==1){//情况2 
					ans*=2;
				}
				else if(vis[i-1]==2){//情况3 
					ans*=1;
				}
				vis[i]=1;
			}
			else{
				if(vis[i-1]==1){
					ans*=2;
				}
				else if(vis[i-1]==2){
					ans*=3;
				}
				vis[i+1]=2;
				i++;
			} 
		}
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}	 
