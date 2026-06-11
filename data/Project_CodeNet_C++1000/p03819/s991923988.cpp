#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;
typedef long long int ll;

template<class V,int ME> class BIT{
public:
	V bit[1<<ME];
	V operator()(int e){V s=0;e++;while(e)s+=bit[e-1],e-=e&-e;return s;}
	V add(int e,V v){e++; while(e<=(1<<ME))bit[e-1]+=v,e+=e&(-e);}
};
BIT<ll,20> bt;

int main(){
	int n,m; cin >> n >> m;
	vector<int> E[101010];
	for(int i=0;i<n;i++){
		int x,y; cin >> x >> y;
		E[y-x+1].push_back(x);
	}
	int mi=n;
	for(int i=1;i<=m;i++){
		int ret=0;
		for(int j=i;j<=m;j+=i){
			ret+=bt(j);
		}
		for(auto e:E[i]){
			bt.add(e,1);
			bt.add(e+i,-1);
		}
		cout << mi+ret << endl;
		mi-=E[i].size();
	}
}