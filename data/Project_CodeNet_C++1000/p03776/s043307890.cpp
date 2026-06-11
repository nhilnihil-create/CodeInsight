#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000.0

map<pair<int,int>,long long> mp;

long long combination(long long x,long long y){
	if(mp[make_pair(x,y)]!=0)return mp[make_pair(x,y)];
	if(x==0&&y==0)return 1;
	if(y>x||y<0)return 0;
	long long k = combination(x-1,y-1)+combination(x-1,y);
	mp[make_pair(x,y)] = k;
	return k;
}

int main(){
	
	int N,A,B;
	cin>>N>>A>>B;
	
	vector<long long> v(N);
	
	for(int i=0;i<N;i++)cin>>v[i];
	
	sort(v.begin(),v.end(),greater<long long>());
	
	vector<long long> a(A);
	
	double ans = 0.0;
	int A_cnt = 0;
	
	for(int i=0;i<A;i++){
		a[i] = v[i];
		ans += a[i];
		if(v[A-1]==a[i])A_cnt++;
	}
	
	cout<<fixed<<setprecision(20)<<ans/(double)A<<endl;
	
	int B_cnt = 0;
	
	for(int i=0;i<N;i++){
		if(v[A-1]==v[i])B_cnt++;
	}
		
	long long Ans = 0;
	
	if(v[0]==v[A-1]){
		for(int i=A_cnt;i<=min(B-(A-A_cnt),B_cnt);i++){
			Ans += combination(B_cnt,i);
		}
	}
	else{
		Ans = combination(B_cnt,A_cnt);
	}
	
	cout<<Ans<<endl;
		
	
	return 0;
}
