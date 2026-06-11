#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define reverse(x) reverse(x.begin(), x.end())
#define pb push_back
#define pii pair<int, int>
#define pll pair<long long,long long>
#define f first
#define s second
typedef long long ll;
const int mod = 1e9+7;
using namespace std;
int n, m;

int main(){
	int x,a,b;
	cin >> x >> a >> b;
	if(-a+b <= 0){
		cout << "delicious";
	}else if(-a+b <= x){
		cout << "safe";
	}else {
		cout << "dangerous";
	}
}
