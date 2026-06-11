#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n, k;
	cin>> n >> k;
	vector<int> a(n-1);
	
	int a0;
	cin>> a0;
	for(int i=0;i<n-1;i++){
		cin>>a[i];
	}
	
	long long ans = 1E13;
	for(int bit=0;bit<(1<<(n-1));bit++){
		int col = 1;
		vector<bool> look(n-1);
		long long cost = 0;
		for(int i=0;i<n-1;i++){
			if(bit&(1<<i)){
				look[i] = 1;
				col++;
			}
		}
		if(col<k) continue;
		
		int hight = a0;
		for(int i=0;i<n-1;i++){
			if(look[i]){
				if(a[i]<hight+1){
					cost += (hight+1-a[i]);
					hight++;
				}else{
					hight = a[i];
				}
			}else{
				if(hight<a[i]){
					hight = a[i];
				}
			}
		}
		if(cost<ans) ans = cost;
	}
	cout<<ans<<endl;
}
