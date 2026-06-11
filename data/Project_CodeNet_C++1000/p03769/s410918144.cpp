#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
ll n;
int main(){
	cin>>n;
	n++;
	vector<int>vec;
	vector<int>vec2;
	for(int i=63;i>=0;i--){
		if(!((n>>i)&1)) continue;
		for(int j=1;j<=i;j++){
			vec.pb(j);
			vec2.pb(j);
		}
		int nxt = i+1;
		for(int j=i-1;j>=0;j--){
			if(!((n>>j)&1)) continue;
			reverse(vec2.begin(),vec2.end());
			vec2.pb(nxt);
			reverse(vec2.begin(),vec2.end());
			stack<int>S;
			for(int k=0;k<j;k++){
				S.push(vec[vec.size()-1]);
				vec.pop_back();
			}
			vec.pb(nxt);
			for(int k=0;k<j;k++){
				vec.pb(S.top());
				S.pop();
			}
			nxt++;
		}
		break;
	}
	cout<<vec.size()+vec2.size()<<endl;
	for(int i=0;i<vec.size();i++) cout << vec[i] << " ";
	for(int i=0;i<vec2.size();i++) cout << vec2[i] << " ";
	cout<<endl;
}