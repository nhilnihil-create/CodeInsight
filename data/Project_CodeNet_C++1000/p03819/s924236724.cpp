#include <bits/stdc++.h>

using namespace std;

typedef long long lli;
typedef double lld;
typedef vector<lli> vll;
typedef vector<bool> vbl;
typedef vector<double> vdl;
typedef vector<vector<lli>> mat;
typedef vector<vdl> mad;
typedef unordered_map<lli,unordered_map<lli,lli>> graph;
typedef complex<double> cmp;
typedef vector<cmp> vcl;

lli n,m;
mat lr;

class bit {
private:
	vll* v;
	lli n;
public:
	bit (lli n) {
		this->v = new vll(n+1);
		this->n = n;
	}
	void add(lli i,lli val){
		for(;i <= n;i += i&-i) this->v->at(i) += val;
	}
	lli sum(lli i){
		lli ret = 0;
		for(;i > 0;i -= i&-i) ret += this->v->at(i);
		return ret;
	}
};


int main(){
  cin >> n >> m;
  lr = mat(n);
  for(lli i = 0;i < n;i++){
    lli l,r;
    cin >> l >> r;
    lli d = r-l+1;
    lr[i] = vll({d,l,r});
  }
  sort(lr.begin(),lr.end());
  bit bt = bit(m+1);
  for(lli d = 1,i = 0;d <= m;d++){
    while(i < n && lr[i][0] <= d){
      bt.add(lr[i][1],1);
      bt.add(lr[i][2]+1,-1);
      i++;
    }
    lli ans = n-i;
    for(lli i = d;i <= m;i += d){
      ans += bt.sum(i);
    }
    cout << ans << endl;
  }
  return 0;
}
