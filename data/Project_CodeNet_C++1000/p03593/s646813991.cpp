#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)


// Write From This Line
int main()
{
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i,h) cin >> s[i];
	vector<int> count(26,0);
	rep(i,h){
		rep(j,w){
			int c = s[i][j] - 'a';
			count[c] += 1;
		}
	}

	int need4, need2;
	need4 = (h / 2) * (w / 2) ;
	need2 = (h/2) * (w%2) + (w/2) * (h%2);

	rep(i,26){
		while(count[i] >= 4){
			if(need4 == 0) break;
			count[i] -= 4;
			need4 --;
		}
	}
	rep(i,26){
		while(count[i] >= 2){
			if(need2 == 0) break;
			count[i] -= 2;
			need2 --;
		}
	}
	if(need4 + need2){
		puts("No");
	} else {
		puts("Yes");
	}

}
