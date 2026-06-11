//Nipah!~☆
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;

string ANS[] = {"Second", "First"};

int n, t;
int a[maxn];
string ans;

void in();
int solve();
void fix();
void out();

int main(){
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	in();
	ans = ANS[solve()];
	out();
}

void in(){
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
}

int solve(){
	t = 0;
	int z = 0;
	for(int i = 0; i < n; i++){
		t += a[i] % 2;
		if(a[i] == 1)
			z++;
	}
	if(n == 1)
		return 0;
	if(n % 2 != t % 2)
		return 1;
	if(n % 2 == t % 2 && t % 2 == 0)
		return 0;
	else if(t != 1 || z)
		return 0;
	else{
		for(int i = 0; i < n; i++)
			if(a[i] % 2)
				a[i]--;
		fix();
		int b = solve();
		return 1 - b;
	}
}

void fix(){
	int gcd = 0;
	for(int i = 0; i < n; i++)
		gcd = __gcd(gcd, a[i]);
	for(int i = 0; i < n; i++)
		a[i] /= gcd;
}

void out(){
	cout << ans;
}