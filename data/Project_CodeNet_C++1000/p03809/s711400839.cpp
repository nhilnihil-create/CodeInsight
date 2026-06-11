#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
ll n,i,a[101010],D[101010],R,ta,tb;
vector<ll> v[101010];
ll dfs(ll aa,ll bb)
{
	if(D[aa]==1)
		return a[aa];
	ll ii;
	vector<ll> isi;
	for(ii=0;ii<v[aa].size();ii++)
	{
		if(v[aa][ii]!=bb)
			isi.pb(dfs(v[aa][ii],aa));
	}
	sort(isi.begin(),isi.end());
	ll sz=isi.size(),jum=0,sisa;
	for(ii=0;ii<sz;ii++)
		jum+=isi[ii];
	sisa=jum-a[aa];
	//cout<<aa<<" "<<jum<<" "<<a[aa]<<" "<<D[aa]<<"_\n";
	//cout<<sisa<<"\n";
	if(sisa<0)
	{
		cout<<"NO\n";
		exit(0);
	}
	ll Z=a[aa]-sisa;
	jum-=Z;
	if((jum%2)==1)
	{
		cout<<"NO\n";
		exit(0);
	}	
	//cout<<isi[sz-1]<<" "<<
	//cout<<jum<<"\n";
	if((isi[sz-1]-Z)>(jum/2))
	{
		cout<<"NO\n";
		exit(0);
	}
	if(Z<0)
	{
		cout<<"NO\n";
		exit(0);
	}
	//cout<<aa<<" "<<Z<<"\n";
	return Z;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	if(n==2)
	{
		if(a[1]==a[2])
			cout<<"YES\n";
		else 
			cout<<"NO\n";
		return 0;
	}
	for(i=1;i<n;i++)
	{
		cin>>ta>>tb;
		v[ta].pb(tb);
		v[tb].pb(ta);
		D[ta]++;
		D[tb]++;
	}
	R=1;
	for(i=1;i<=n;i++)
		if(D[i]>1)
		{
			R=i;
			break;
		}
	//cout<<R<<"\n";
	//for(i=1;i<=n;i++)
	//	cout<<i<<"_"<<D[i]<<"\n";
	if(dfs(R,R)==0)cout<<"YES\n";
	else cout<<"NO\n";
}