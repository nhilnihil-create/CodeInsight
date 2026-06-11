#include<bits/stdc++.h>
using namespace std;
typedef long long signed int ll;
int main(){
	int n,m;
	cin>>n>>m;
	bool visit[n+1];
	memset(visit,false,sizeof(visit));
	int arr[n+1];
	
	for(int i=0;i<=n;i++) arr[i] = 1;
	

	int x,y;
	int cur = 1;
	int one = 0;
	int tot = 0;
	visit[1] = true;
	for(int i=0;i<m;i++){
		cin>>x>>y;
		if(visit[x]==true && arr[x]>=1) {
			
				
				visit[y] = true;
				
				arr[x]--;
				arr[y]++;
				if(arr[x]==0) {
					visit[x] = false;
			}
		
		}
		
	   else {
				arr[x]--;
				arr[y]++;
				
		}
	
		
	}
	for(int i=1;i<=n;i++) if(visit[i]==true) tot++;
	cout<<tot<<endl;
	return 0;
}
	
	