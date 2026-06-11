#include<bits/stdc++.h>
using namespace std;

long long int  a[100000],b[100000];
vector<long long int> v;
map<long long int,int> m;
int cnt[100001];
long long int pre[100001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		v.emplace_back(a[i]);
	}
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	for(int i=0;i<v.size();i++)
		m[v[i]]=i;
	for(int i=0;i<n;i++)
		b[i]=m[a[i]];
	for(int i=0;i<n;i++)
		cnt[m[a[i]]]++;
	long long int tmp=n;
	pre[0]=tmp*v[0];
	for(int i=1;i<v.size();i++){
		tmp-=cnt[i-1];
		pre[i]=pre[i-1]+tmp*(v[i]-v[i-1]);
	}
	long long int now=-1;
	for(int i=0;i<n;i++){
		if(now==-1){
			cout<<pre[b[i]]<<'\n';
			now=b[i];
		}
		else if(b[i]>now){
			cout<<pre[b[i]]-pre[now]<<'\n';
			now=b[i];
		}
		else
			cout<<0<<'\n';
	}
}