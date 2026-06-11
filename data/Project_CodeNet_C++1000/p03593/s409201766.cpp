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
	if(h * w == 1){
		puts("Yes");
		return 0;
	}
	else if(h * w == 2){
		bool flag = true;
		char c = '.';
		rep(i,h) rep(j,w) {
			if(c == '.') c = s[i][j];
			else {
				if(c != s[i][j]) flag = false;
			}
		}
		if(flag) puts("Yes");
		else puts("No");
		return 0;
	}
	// とりあえず処理をまとめないで i * k or k * 1 のときを書く
	if (h == 1 || w == 1){
		int need = (h * w) / 2;
		rep(i,26){
			if(count[i] >= 2){
				need -= count[i] / 2;
			}
		}
		if(need == 0){
			puts("Yes");
		} else {
			puts("No");
		}
		return 0;
	}

	//cout << "ikiteru" << endl;
	int need4, need2;
	need4 = (h / 2) * (w / 2) ;
	need2 = (h/2) * (w%2) + (w/2) * (h%2);
	//cout << "need4 = " << need4 << endl;
	//cout << "need2 = " << need2 << endl;
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
	if(need4 == 0 && need2 == 0){
		puts("Yes");
	} else {
		puts("No");
	}

}
