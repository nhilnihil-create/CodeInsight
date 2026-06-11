#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,k,w[N],q[N];
int main(){
	cin>>n>>n;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++) if(w[i]%2==1) swap(w[1],w[i]);
	for(int i=2;i<=n;i++) if(w[i]%2==1) swap(w[n],w[i]);
	for(int i=2;i<n;i++) if(w[i]%2==1) k++;
	if(k>0){
		puts("Impossible"); return 0;
	}
	for(int i=1;i<=n;i++) cout<<w[i]<<" "; cout<<endl;
	w[1]--; if(n==1) w[++n]=1; else w[n]++;
	for(int i=1;i<=n;i++) if(w[i]) q[++q[0]]=w[i];
	cout<<q[0]<<endl;
	for(int i=1;i<=q[0];i++) cout<<q[i]<<" "; cout<<endl;
}