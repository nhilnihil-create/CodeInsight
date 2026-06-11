#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
using P = pair<int,int>;
using ll = long long;
static const int INF = 1000000000;
static const ll MOD = 1000000007;

ll gcd(ll a, ll b){return b!=0 ? gcd(b, a%b) : a;}
ll lcm(ll a, ll b){return a / gcd(a, b) * b;}

int main(){
	const int card[] = {13, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	int a, b;
	cin >> a >> b;
	if(card[a-1] < card[b-1]){
		cout << "Bob" << endl;
	}
	else if(card[a-1] > card[b-1]){
		cout << "Alice" << endl;
	}
	else{
		cout << "Draw" << endl;
	}
	return 0;
}

