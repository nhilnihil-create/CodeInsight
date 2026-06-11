#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main() {
	string s;
	cin >> s;

	map<char, int> m;
	for (int ii = 0; ii < s.size(); ++ii){
		m[s[ii]]++;
	}

	int minCnt = 100100100;
	for (char c = 'a'; c <= 'z'; ++c){
		if (m[c] == 0) continue;

		string tmp = s;
		for (int cnt = 0; cnt < s.size(); ++cnt){
			//文字列に含まれるアルファベットが1種類だけなら抜ける
			bool OK = true;
			for (int ii = 1; ii < tmp.size(); ++ii){
				if (tmp[0] != tmp[ii]){
					OK = false;
					break;
				}
			}
			if (OK){
				minCnt = min(minCnt, cnt);
				break;
			}
			//処理
			for (int ii = 0; ii < tmp.size() - 1; ++ii){
				if ( (tmp[ii] == c) || (tmp[ii+1] == c) ){
					tmp[ii] = c;
				}
			}
			tmp.erase(tmp.size() - 1);
		}
	}

	cout << minCnt << endl;


	return 0;
}
