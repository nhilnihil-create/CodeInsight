#include <bits/stdc++.h>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define N 1000005
using namespace std;

typedef long long ll;

ll a, b;

int main() {
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	scanf("%lld %lld",&a ,&b);
	if(abs(a - b) <= 1)
		printf("Brown\n");
	else
		printf("Alice\n");

	return 0;
}