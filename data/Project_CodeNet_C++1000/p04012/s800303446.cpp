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
const int MAX = 1e5+5;
int mp[30], ok = 1;
char s[MAX];

int main(int argc, char ** argv) {
	scanf(" %s", s);
	rep(i, 0, strlen(s))
	    mp[s[i]-'a']++;
	rep(i, 0, 30) if(mp[i]&1) ok = 0;
	printf("%s\n", ok ? "Yes" : "No");
	return 0;
}
