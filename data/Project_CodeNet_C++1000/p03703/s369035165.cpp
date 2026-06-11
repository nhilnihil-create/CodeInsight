#include <bits/stdc++.h>
#define pb push_back
#define ll long long
#define mp make_pair
#define inf 1000000007
#define int long long
using namespace std;
vector<int> b;
int nn;
ll seg[530000];
void init(int n_){
	nn = 1;
	while(nn<n_)nn*=2;
	for(int i=0;i<2*nn-1;i++)seg[i]=0;
}

void update(int k,int a){
	k += nn-1;
	seg[k]+=a;
	while(k>0){
		k = (k-1)/2;
		seg[k] = seg[k*2+1]+ seg[k*2+2];
	}
}

ll query(int a,int b, int k, int l, int r){
	if(r<=a || b<=l) return 0;
	if(a<=l && r<=b) return seg[k];
	else{
		ll vl = query(a,b,k*2+1,l,(l+r)/2);
		ll vr = query(a,b,k*2+2,(l+r)/2,r);
		return vl+vr;
	}
}
signed main(){
	int n,k;
	cin>>n>>k;
	vector<int> a;
	a.pb(0);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.pb(x);
	}
	int sum = 0;
	for(int i=0;i<=n;i++){
		sum += a[i];
		b.pb(sum-i*k);
	}
	vector<int> vec;
	vector<int> c;
	vec=b;
	map<int,int> iidx;
	sort(vec.begin(),vec.end());
	vec.erase( unique(vec.begin(),vec.end()), vec.end() );
	for(int i=0;i<vec.size();i++){
		iidx[ vec[i] ] = i;
	}
	for(int i=0;i<=n;i++){
		c.pb(iidx[b[i]]);
	}
	int cnt=0;
	init(n);
	for(int i=n;i>=0;i--){
		cnt += query(0,c[i],0,0,nn);
		update(c[i],1);
	}
	cout<<(n+1)*n/2-cnt<<endl;
	return 0;
}