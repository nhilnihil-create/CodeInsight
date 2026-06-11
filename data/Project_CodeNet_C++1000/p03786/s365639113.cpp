#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n) cin >> a[i];
	sort(a.begin(), a.end());
	vector<ll> r(n+1);
	rep(i, n) r[i + 1] = r[i] + a[i];
    int k=0;
	rep(i, n){
      if(i==0) continue;
      if(a[i]>2*r[i]) k=i;
    }
    cout<<n-k<<endl;
}
