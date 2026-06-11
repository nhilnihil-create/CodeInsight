#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
vector<int>odd;
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];if(a[i]&1)odd.push_back(i);
	}
	if(m==1){
		cout<<n<<endl;
		if(n==1){
			cout<<1<<endl<<1<<endl;
			return 0;
		}
		cout<<2<<endl;
		cout<<n-1<<" "<<1<<endl;
		return 0;
	}
	if(odd.size()>2){
		puts("Impossible");
		return 0;
	}
	if(odd.size())swap(a[1],a[odd[0]]);
	if(odd.size()>1){
		swap(a[m],a[odd[1]]);
	}
	for(int i=1;i<=m;i++)cout<<a[i]<<" ";cout<<endl;
	a[1]++;a[m]--;int N=0;
	for(int i=1;i<=m;i++)if(a[i])N++;
	cout<<N<<endl;
	for(int i=1;i<=m;i++){
		if(a[i])cout<<a[i]<<" ";
	}
	return 0;
}