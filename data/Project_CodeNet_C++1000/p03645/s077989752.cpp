#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mx 1

int main()
{	
	ios_base::sync_with_stdio(0);
	int n,m,a,b;
	while(cin>>n>>m){
		vector<int> arr(n,0);
		int ok = 0;
		for(int i=1; i<=m; i++){
			cin>>a>>b;
			if(a==1 || a==n){
				arr[b-1]++;
				if(arr[b-1]==2) ok = 1;
			}
			if(b==1 || b==n){
				arr[a-1]++;
				if(arr[a-1]==2) ok = 1;
			}
		}
		if(ok) cout<<"POSSIBLE"<<endl;
		else cout<<"IMPOSSIBLE"<<endl;
	}
}

