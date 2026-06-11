#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
bool query(ll x){cout<<"? "<<x<<endl;string s;cin>>s;return s[0]=='Y';}
void output(int x){cout<<"! "<<x<<endl;exit(0);}

int f[100];
int main(){
	f[0]=1;
	for(int i=1,j=10;i<=9;++i,j*=10)f[i]=query(j);
	if(!f[9]){
		for(int i=1,j=10;i<=9;++i,j*=10)
			if(!f[i]){
				ll l=j,r=j*10ll-1;
				while(l<r){
					ll mid=(l+r)/2;
					if(query(mid))r=mid;
					else l=mid+1;
				}
				output(l/10);
			}
	}else{
		int l=0,r=100000000;
		while(l<r){
			int mid=(l+r)/2;
			if(query(10*mid+2))r=mid;
			else l=mid+1;
		}
		output(max(1,l*10));
	}
	return 0;
}
