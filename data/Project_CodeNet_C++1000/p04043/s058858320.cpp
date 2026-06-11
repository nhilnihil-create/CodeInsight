#include <bits/stdc++.h>
using namespace std;
 
#define REP(i, a, b) for(int i = (a); i <= (b); i++)
#define PER(i, a, b) for(int i = (a); i >= (b); i--)
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define all(S) (S).begin(), (S).end()
#define pb push_back
#define mk make_pair
#define S second
#define F first
typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
typedef pair<ll, ll> pl;
typedef pair<pl, ii> pli;
const int MAX = 2e5+5;

int main(int argc, char * * argv) {
	vector<int> a(3);
  	for(auto &x : a)
      	scanf("%d", &x);
  	sort(all(a));
  	if(a[0] == 5 && a[1] == 5 && a[2] == 7)
		puts("YES");
  	else puts("NO");
	return 0;
}
