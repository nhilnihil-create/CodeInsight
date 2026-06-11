#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define ff first
#define ss second
#define pb push_back
#define debug(val) cerr << "The value of " << #val << " is = " << val << '\n';
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f;
const ll mininf = -922337203685477;
const ll nax = 0;
int n, m, x[55], y[55], a[55], b[55];

int main(){
	IOS
	cin >> n >> m;	
	for(int i=0;i<n;i++){
		cin >> x[i] >> y[i];
	}
	for(int i=0;i<m;i++){
		cin >> a[i] >> b[i];
	}
	for(int i=0;i<n;i++){
		int temp;
		int mins=inf;
		for(int j=0;j<m;j++){
			int manhattan=abs(x[i]-a[j])+abs(y[i]-b[j]);
			if(manhattan<mins) temp=j+1;	
			mins=min(mins, manhattan);
		}
		cout << temp << '\n';
	}
}
