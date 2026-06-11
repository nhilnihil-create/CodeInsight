#include<bits/stdc++.h>
using namespace std;

long long int h,w;

int n;

map<pair<int,int>,int> ma;

long long int ans[10];

int main(){
	cin >> h >> w >> n;
	for(int i=1;i<=n;i++){
		int a,b;
      
		cin >> a >> b;
      
		for(int j=-1;j<=1;j++){
			for(int k=-1;k<=1;k++){
				int nx = a+j;
				int ny = b+k;
				if(nx < 2 || nx > h-1 || ny < 2 || ny > w-1) continue;
              
				ma[make_pair(nx,ny)]++;
			}
		}
	}
	long long int res = (h-2)*(w-2);
	for(auto x : ma ){
		res--;
		ans[x.second]++;
	}
	ans[0] = res;
  
	for(int i=0;i<=9;i++){
		cout << ans[i] << endl;
      
	}
	return 0;
}
