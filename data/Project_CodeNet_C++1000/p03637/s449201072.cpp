#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 100000000000000

int main(){
	int n;cin>>n;
	vector<int> a(n);for(int i=0;i<n;i++){cin>>a[i];}

	vector<int> spare(4,0);
	for(int i=0;i<n;i++){
		spare[a[i]%4]++;
	}

	bool ok=true;

	if(spare[1]+spare[3]>spare[0] && !(spare[1]+spare[3]==spare[0]+1 && spare[1]+spare[3]+spare[0]==n)){ok=false;}//oddが存在する時点でその数以上の4の倍数が必要(mod4が　1 0 1 0 1のようになる場合は例外)
	if(spare[0]==0 && spare[1]+spare[3]>=1){ok=false;}

	if(ok){cout<<"Yes"<<endl;}
	else{cout<<"No"<<endl;}
	return 0;
}