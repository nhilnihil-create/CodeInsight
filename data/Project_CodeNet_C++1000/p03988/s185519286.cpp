#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000


int main(){
	
	int N;
	cin>>N;
	
	vector<long long> a(N);
	for(int i=0;i<N;i++)cin>>a[i];
	
	sort(a.begin(),a.end());
	
	int K = a[a.size()-1];
	int K2 = a[0];
	map<int,int> mp;
	if(K%2==0){
		for(int i=1;i<N;i++){
			mp[a[i]]++;
		}
	}
	else{
		K--;
		for(int i=2;i<N;i++){
			mp[a[i]]++;
		}
	}
	
	if(mp[K2]!=0){
		cout<<"Impossible"<<endl;
		return 0;
	}
	
	for(int i=K2+1;i<=K;i++){
		if(mp[i]<=1){
			cout<<"Impossible"<<endl;
			return 0;
		}
	}
	
	cout<<"Possible"<<endl;
	
	return 0;
}
