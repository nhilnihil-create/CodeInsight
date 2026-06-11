#include <bits/stdc++.h>

#define f first 
#define s second 
#define pb push_back               
#define all(x) x.begin(), x.end())

using namespace std;                    

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)1e6 + 123, mod = (int)1e9 + 7, inf = (int)1e9, LOG = 18;
const ll INF = (ll)1e8;
const double eps = 1e-9;

int n, a[N], b[N];
bool check(int x){
	for(int i = 1; i <= n; i++)
		if(a[i] <= x)
			b[i] = 0;
		else
			b[i] = 1;
	
	bool ok1, ok2;
	ok1 = 1;         
	ok2 = 1;        
	for(int i = 1; i <= n; i++)
		if(b[i] == i % 2)
			ok1 = 0;
	 	else
			ok2 = 0;
    
    if(ok1 || ok2){
		int cnt = (n + 1) / 2 - 1;
        return b[n/2 + 1] ^ (cnt & 1);
	}
	for(int i = 1; ; i++){
		if(b[n / 2 + 1 + i] == b[n / 2 + 1 - i] && b[n / 2 + 1 + i] != b[n / 2  + i])
			continue;               
		if(b[n / 2 + 1 + i] == b[n / 2  + i])
			return b[n / 2 + 1 + i];
		else
			return b[n / 2 + 1 - i]; 
	}
}
int main(){
	cin >> n;
	n = n + n - 1;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int l = 1, r = n;
	while(l <= r){
		int m = l + r >> 1;
		if(check(m))
			l = m + 1;
		else
			r = m - 1;
	}
	cout << l;
}