#include<bits/stdc++.h>
using namespace std;

int p[200001];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		p[x]=i;
	}
	long long int ans=0;
	set<int> s;
	s.insert(0);
	s.insert(n+1);
	for(int i=1;i<=n;i++){
		int x=p[i];
		auto it=s.insert(x).first;
		ans+=1LL*i*(x-(*prev(it)))*(*next(it)-x);
	}
	cout<<ans<<endl;
}

