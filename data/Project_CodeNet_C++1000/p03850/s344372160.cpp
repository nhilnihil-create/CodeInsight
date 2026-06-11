#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
const int oo = 1e9;
const int MOD = 1000000007;
const int BASE = 26;
const int N = 200001;
#define pb push_back
#define mp make_pair
#define x first
#define y second

int n,a[N];
ll pre[N],sn[N];
char op[N],tmp[10];

int main() {
	scanf("%d",&n);
	scanf("%d",&a[1]);
	pre[1] = sn[1] = a[1];
	for(int i = 2; i <= n ; ++i){
		scanf("%s%d",tmp,&a[i]);
		op[i] = tmp[0];
		pre[i] = a[i] + pre[i-1];
		sn[i] = (tmp[0]=='-'?-1:1)*a[i]+sn[i-1];
		
	}
	ll mx = sn[n];
	int last = -1;
	for(int i = n; i >= 1 ; --i){
		if(op[i]=='-'){
			if(last != -1){
				mx = max(mx,sn[i-1]-(pre[last-1]-pre[i-1])+(pre[n]-pre[last-1]));
			}
			last = i;
		}
	}
	cout << mx << endl;
	return 0;
}
