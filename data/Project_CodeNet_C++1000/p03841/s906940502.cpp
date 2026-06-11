#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000


int main(){
	int N;
	cin>>N;
	
	vector<int> ans(N*N,-1);
	
	vector<pair<int,int>> x(N);
	for(int i=0;i<N;i++){
		cin>>x[i].first;
		x[i].first--;
		x[i].second=i;
		
		ans[x[i].first] = i;
		
	}
	sort(x.begin(),x.end());
	int now = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<x[i].second;j++){
			while(true){
				if(ans[now]==-1){
					if(now>=x[i].first){
						cout<<"No"<<endl;
						return 0;
					}
					ans[now] = x[i].second;
					break;
				}
				now++;
			}
		}
	}
		
	reverse(x.begin(),x.end());
	now = N*N-1;
	for(int i=0;i<N;i++){
		for(int j=0;j<N-x[i].second-1;j++){
			while(true){
				if(ans[now]==-1){
					if(now<=x[i].first){
						cout<<"No"<<endl;
						return 0;
					}
					ans[now] = x[i].second;
					break;
				}
				now--;
			}
		}
	}
	cout<<"Yes"<<endl;
	for(int i=0;i<N*N;i++){
		if(i!=0)cout<<' ';
		cout<<ans[i]+1;
	}
	cout<<endl;
		
	
	return 0;
}
