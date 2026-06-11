// 21:50 - 21:54
#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define lch (o << 1)
#define rch (o << 1 | 1)

typedef double db;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> pint;

const int N = 50 + 5;
const int INF = 0x3f3f3f3f;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f;

ll s[N];

int main(){
	ios::sync_with_stdio(0);

	ll k; cin >> k;
	for(int i=1; i<=50; i++)
		s[i] = 49;
	ll a = k / 50, b = k % 50;
	for(int i=1; i<=b; i++){
		s[i] += 50;
		for(int j=1; j<=50; j++)
			if(i != j) s[j]--;
	}
	
	cout << 50 << endl;
	for(int i=1; i<=50; i++)
		cout << s[i] + a << " \n"[i == 50];

	return 0;
}