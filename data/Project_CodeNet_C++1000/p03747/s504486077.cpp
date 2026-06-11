#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;
#define N 100010
ll n,L,T,x,w,a,b,num=0;
vector<ll> at;
ll D(ll c,ll d){
	ll ret=c%d;
	if(ret<0)return ret+d;
	return ret;
}
int main(){
	cin>>n>>L>>T>>x>>w;
	ll oneant;
	if(w==1)oneant=D(x+T,L);
	if(w==2)oneant=D(x-T,L);
	at.push_back(oneant);
	lol(i,n-1){
		cin>>a>>b;
		if(b==1){
			at.push_back(D(a+T,L));
			if(w==2){
				num=D(num-(2*T+L-D(x-a,L))/L,n);
			}
		}
		if(b==2){
			at.push_back(D(a-T,L));
			if(w==1){
				num=D(num+(2*T+L-D(a-x,L))/L,n);
			}
		}
	}
	sort(at.begin(),at.end());
	int p;
	lol(i,n){
		if(at[i]==oneant){
			p=i;
			if(w==2)break;
		}
	}
	p=D(p-num,n);
	lol(i,n){
		cout<<at[p]<<endl;
		p=(p+1)%n;
	}
	return 0;
}
