#include <bits/stdc++.h>

using namespace std;
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)


int main()
{
	int h, w;
	cin >> h >> w;
	vector<int> count(26,0);
	rep(i,h){
		string s;
		cin >> s;
		rep(j,w){
			int c = s[j] - 'a';
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
