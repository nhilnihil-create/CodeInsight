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

int main(int argc, char ** argv) {
	char s[20];
	stack<char> p, t;
	scanf(" %s", s);
	rep(i, 0, strlen(s)) {
	    if(s[i] == 'B' && !p.empty()) p.pop();
	    else if(s[i] != 'B') p.push(s[i]);
	}
	while(!p.empty()) t.push(p.top()), p.pop();
	while(!t.empty()) printf("%c", t.top()), t.pop();
	printf("\n");
	return 0;
}
