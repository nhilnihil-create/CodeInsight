#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N,M;
vector<ll> edgeList[100010];
bool isInPath[100010]={};
void MakePath(ll n,vector<ll>& pathVec){
	isInPath[n]=true;
	pathVec.push_back(n);
	for(auto to:edgeList[n]){
		if(!isInPath[to]){
			MakePath(to,pathVec);
			break;
		}
	}
}
int main(){
    cin>>N>>M;
	for(ll i=0;i<M;i++){
		ll a,b;
		cin>>a>>b;
		edgeList[a].push_back(b);
		edgeList[b].push_back(a);
	}
	vector<ll> v1,v2;
	MakePath(1,v1);
	MakePath(1,v2);
	reverse(v1.begin(),v1.end());
	cout<<v1.size()+v2.size()-1<<endl;
	for(auto v:v1){
		cout<<v<<" ";
	}
	for(ll i=1;i<v2.size();i++){
		cout<<v2[i]<<" ";
	}cout<<endl;
    return 0;
}