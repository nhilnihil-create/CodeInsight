#include<bits/stdc++.h>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long int ll;
typedef pair<int,int> P;
const ll MOD=1000000007;
const ll INF=1000000010;
const ll LINF=4000000000000000010LL;
const int MAX=310;
const double EPS=1e-3;
int dx[4]={0,1,0,1};
int dy[4]={0,0,1,1};
int ans[250010];
int main(){
	int n;cin>>n;
	vector<P> v;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		v.push_back(P(x,i));
	}
	sort(all(v));
	int nn=n*n;
	int c[510];
	bool f=false;
	int idx=1;
	for(int i=1;i<=n;i++){
		c[i]=n;
	}
	for(int i=0;i<v.size();i++){
		int x=v[i].first;int p=v[i].second;
		ans[x]=p;
		c[p]--;
		for(int j=idx;j<x;j++){
			if(c[p]==n-p){
				break;
			}
			if(ans[j]){
				continue;
			}
			ans[j]=p;
			c[p]--;
			idx++;
		}
		if(c[p]!=n-p)f=true;
		if(f)break;
	}
	idx=1;
	for(int i=0;i<v.size();i++){
		int p=v[i].second;int x=v[i].first;
		for(int j=idx;j<=nn;j++){
			if(c[p]==0){
				break;
			}
			if(ans[j]){
				continue;
			}
			if(j<x){
				f=true;
				break;
			}
			ans[j]=p;
			c[p]--;
			idx++;
		}
	}
	if(f){
		cout<<"No"<<endl;
	}else{
		cout<<"Yes"<<endl;
		for(int i=1;i<=nn;i++){	
			cout<<ans[i];
			if(nn-i){
				cout<<" ";
			}
		}
		cout<<endl;
	}
    return 0;
}
