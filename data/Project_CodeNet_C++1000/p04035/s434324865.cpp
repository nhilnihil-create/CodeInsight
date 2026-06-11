#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2000006;
const ll MOD = 1e9+7;

int a[N];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int n,l;
	cin>>n>>l;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int idx = -1;
	for(int i=1;i<n;i++){
		if(a[i]+a[i-1] >= l){
			idx = i-1;
			break;
		}
	}
	if(idx == -1){
		cout<<"Impossible"<<endl;
	}else{
		cout<<"Possible"<<endl;
		for(int i=0;i<idx;i++){
			cout<<i+1<<endl;
		}
		for(int i=n-1;i>idx;i--){
			cout<<i<<endl;
		}
	} 
	
	return 0;
}
