#include <bits/stdc++.h>

using namespace std;

int main() {

	string s;
	cin >> s;

	if (s.size() == 1) {
			cout << 0 << endl;
			return 0;
	}

	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] != s[i + 1]) { break; }
		if (i == s.size() - 2) {
			cout << 0 << endl;
			return 0;
		}
	}

	string sorigin = s;
	string news;
	int counter;
	int countermin = 10000;
	for (int i = (char)'a'; i <= (char)'z'; i++) {
		s = sorigin;
		bool opflg = false;
		for (int j = 0; j < s.size() - 1; j++) {
			if (s[j] == i) {
				opflg = true;
				break;
			}
		}
		if (opflg) {
			counter = 0;
			while (1) {
				news = "";
				for (int j = 0; j < s.size() - 1; j++) {
					if (s[j] == i || s[j + 1] == i) {
						news.push_back((char)i);
					}
					else {
						news.push_back(s[j]);
					}

				}
				counter++;
				bool brkflg = true;
				for (int j = 0; j < news.size(); j++) {
					if (news[j] != i) {
						brkflg = false;
						break;
					}
				}
				if (brkflg) {
					countermin = min(countermin, counter);
					break;
				}
				s = news;
			}
		}
	}

	cout << countermin << endl;

	return 0;

}