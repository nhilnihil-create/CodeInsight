#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	long long H,W;
	cin>>H>>W;
	
	int N;
	cin>>N;
	
	set<pair<int,int>> S;
	
	for(int i=0;i<N;i++){
		int a,b;
		cin>>a>>b;
		S.insert(make_pair(a,b));
	}
	
	vector<long long> ans(10);
	for(auto a:S){
		int x = a.second;
		int y = a.first;
		
		for(int i=x-2;i<x-2+3;i++){
			for(int j=y-2;j<y-2+3;j++){
				
				if(i<=0||j<=0||i+2>W||j+2>H)continue;
				int cnt = 0;
				for(int yy = 0;yy<3;yy++){
					for(int xx=0;xx<3;xx++){
						if(S.count(make_pair(j+xx,i+yy)))cnt++;
					}
				}
				ans[cnt]++;
			}
		}
				
				
		
	}
	
	ans[0] = (H-2)*(W-2);
	for(int i=1;i<10;i++){
		ans[i] /= i;
		ans[0]-=ans[i];
	}
	
	for(int i=0;i<10;i++){
		cout<<ans[i]<<endl;
	}
		
		
	
	return 0;
}
