#include<bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define ll long long
#define maxn 100005
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define ms(i) memset(i,0,sizeof(i));
#define ms1(i) memset(i,-1,sizeof(i));
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9+7;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int cnt = 0;
	int n;
	cin >> n;
	f1 (n) {
		int x;
		cin >> x;
		if (x % 2) {
			cnt++;
		}
	}
	if (cnt % 2) {
		cout << "NO\n";
	}
	else {
		cout << "YES\n";
	}
}
