#include<bits/stdc++.h>
using namespace std;
#define all(vec) vec.begin(),vec.end()
typedef long long int ll;
typedef pair<int,int> P;
typedef pair<P,P> PP;
const ll MOD=10000;
const ll INF=1000000010;
const int MAX=100001;
int dx[8]={0,1,0,-1,1,-1,1,-1};
int dy[8]={1,0,-1,0,1,-1,-1,1};
template< class T >
struct BinaryIndexedTree
{
  vector< T > data;

  BinaryIndexedTree(int sz)
  {
    data.assign(++sz, 0);
  }

  T sum(int k)
  {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x)
  {
    for(++k; k < (int)data.size(); k += k & -k) data[k] += x;
  }
};
int main(){
	int n,m;cin>>n>>m;
	vector<pair<int,P> > v;
	for(int i=0;i<n;i++){
		int l,r;cin>>l>>r;
		v.push_back(make_pair(r-l+1,P(l,r)));
	}
	sort(v.begin(),v.end());
	BinaryIndexedTree<int> bit(m+1);
	int idx=0;
	for(int i=1;i<=m;i++){
		while(v[idx].first<i&&idx<n){
			bit.add(v[idx].second.first,1);
			bit.add(v[idx].second.second+1,-1);
			idx++;
		}
		int ans=n-idx;
		for(int j=i;j<=m;j+=i){
			ans+=bit.sum(j);
		}
		cout<<ans<<endl;
	}
	return 0;
}
