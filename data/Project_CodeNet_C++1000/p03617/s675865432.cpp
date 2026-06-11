#include <iostream>
#include <algorithm>
#include <string>
#include <limits.h>
#include <vector>
#include <numeric>

using namespace std;

vector<pair<long long int, long long int>> getPrimeElements(long long int num) {

	long long int firstnum = num;

	vector<pair<long long int, long long int>> result;
	pair<long long int, long long int> wk;

	if (num % 2 == 0) {
		wk.first = 2;
		wk.second = 0;
		while (num % 2 == 0) {
			wk.second++;
			num /= 2;
		}

		result.push_back(wk);
	}

	long long int waru = 3;

	while (true) {

		if (num % waru == 0) {
			wk.first = waru;
			wk.second = 0;
			while (num % waru == 0) {
				wk.second++;
				num /= waru;
			}

			result.push_back(wk);
		}
		waru += 2;

		if (waru * waru > num) break;

	}

	if (num != 1) {
		wk.first = num;
		wk.second = 1;
		result.push_back(wk);

	}

	return result;
}


int getKeta(int num) {

	if (num == 0)return 1;

	int res = 0;

	while (num > 0) {
		num /= 10;
		res++;
	}

	return res;
}

vector<int> bunkai(int num) {

	string str = to_string(num);
	vector<int> res;

	for (int i = 0; i < str.size(); i++) {
		int a = str[i] - '0';
		res.push_back(a);
	}

	return res;

}


int main()
{
    
	long long int q, h, s, d;
	cin >> q >> h >> s >> d;

	long long int n;
	cin >> n;
	n *= 4;

	vector<pair<long long int, long long int>> a;
	pair<long long int, long long int> wk;
	
	wk.first = 1;
	wk.second = q;
	a.push_back(wk);

	wk.first = 2;
	wk.second = h;
	a.push_back(wk);

	wk.first = 4;
	wk.second = s;
	a.push_back(wk);

	wk.first = 8;
	wk.second = d;
	a.push_back(wk);

	bool flg = true;
	while (flg) {

		flg = false;

		for (int i = 0; i < 4 - 1; i++) {
			if ((a[i].second * 8) / a[i].first > (a[i+1].second * 8) / a[i+1].first) {
				wk = a[i];
				a[i] = a[i + 1];
				a[i + 1] = wk;
				flg = true;
			}
		}
	}

	long long int ans = 0;

	for (int i = 0; i < a.size(); i++) {

		ans += (n / a[i].first) * a[i].second;
		n %= a[i].first;

	}


	cout << ans << endl;




	return 0;

}


