//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

//gcdをユークリッド互除法で求める。O(log n)
int euclid(int x, int y){
    if(min(x, y) ==  0) return max(x, y);
    else return euclid(max(x, y)% min(x, y) , min(x, y));
}

int main() {
	int ans = 0;
	int a, b, c;
	cin >> a >> b >> c;
	int gc = euclid(a, b);
	if (c % gc == 0) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	//cout << ans << endl;
}