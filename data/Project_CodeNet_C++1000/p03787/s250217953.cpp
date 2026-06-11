#include <bits/stdc++.h>
#define mod 1000000007
#define pb push_back
#define ll long long
using namespace std;
vector<ll> nex[100009],used(100009,0),col(100009,-1);
int main(){
	ll n,m,is=0,nb=0,nnb=0;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		ll x,y;
		cin>>x>>y;
		nex[x].pb(y);
		nex[y].pb(x);
	}
	for(int i=1;i<=n;i++){
		if(used[i]==0){
			used[i]=1;
			if(nex[i].size()==0){
				is++;
			}
			else{
				queue<ll> que;
				vector<ll> old;
				que.push(i);
				old.pb(i);
				col[i]=0;
				ll fl=0;
				while(!que.empty()){
					ll cur = que.front(); que.pop();
					used[cur]=1;
					for(int j=0;j<nex[cur].size();j++){
						if(used[nex[cur][j]]==0){
							que.push(nex[cur][j]);
							old.pb(nex[cur][j]);
							if(col [ nex[cur][j] ] == -1){
								col [ nex[cur][j] ] = col [cur] +1;
							}
							if( (col[nex[cur][j]]-col[cur])%2!=1){
								if(fl==0){
									fl=1;
									nnb++;
								}
							}
						}
					}
				}
				if(fl==0)nb++;
				for(int i=0;i<old.size();i++){
					used[ old[i] ] =1;
				}
			}
		}
	}
	//cout<<is<<" "<<nb<<" "<<nnb<<endl;
	cout<< 2*n*is - is*is + 2*nb*nb + 2*nb*nnb + nnb*nnb<<endl;
	return 0;
}