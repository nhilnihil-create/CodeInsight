#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000000000000

long long dis(long long a,long long b,long long m){
	if(b>=a)return b-a;
	else return b-a+m;
}

int main(){
	
	long long n,m;
	cin>>n>>m;
	
	vector<long long> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]--;
	}
	
	vector<long long> Add(m,0),Del(m,0),DelS(m,0);
	
	for(int i=0;i<n-1;i++){
		Add[(a[i]+1)%m]++;
		Del[a[i+1]]++;
		DelS[a[i+1]]+= dis(a[i],a[i+1],m)-1;
	}
	
	long long ans = Inf;
	long long now = 0;
	long long sa = 0;
	for(int i=0;i<m;i++){
		if(i==0){
			for(int j=0;j<n-1;j++){
				long long x = dis(a[j],a[j+1],m);
				long long y = 1+dis(0,a[j+1],m);
				if(x>y){
					sa--;
					now+=y;
				}
				else now+=x;
			}
				
		}
		//cout<<now<<','<<sa<<endl;
		ans = min(ans,now);
		sa -= Add[i];
		sa += Del[i];
		now += DelS[i];
		now += sa;
	}
	
	cout<<ans<<endl;
	
	return 0;
}