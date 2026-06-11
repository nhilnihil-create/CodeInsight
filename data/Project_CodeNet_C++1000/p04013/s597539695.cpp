#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>


using namespace std;

typedef long long ll;

int main() {
	int n, a;
	cin >> n >> a;
	map<int,int> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		x -= a;
		m[x]++;
	}
	
	map<ll, ll> cnt;
	for (auto it1 = m.begin(); it1 != m.end(); it1++) {
		
		for (int i = 0; i < it1->second; i++) {
			map<ll, ll> tmp_cnt;
			for (auto it2 = cnt.begin(); it2 != cnt.end(); it2++) {
				tmp_cnt[it2->first + it1->first] += it2->second;
				//cout << it2->second << endl;
			}
			tmp_cnt[it1->first]++;

			for (auto it2 = tmp_cnt.begin(); it2 != tmp_cnt.end(); it2++) {

				cnt[it2->first] += it2->second;
			}
			//cout << i << endl;
		}

		/*
		for (auto it2 = cnt.begin(); it2 != cnt.end(); it2++) {

			cout << it2->first << " "<< it2->second << endl;
		}
		cout << endl;
		*/
	}
	cout << cnt[0] << endl;
}
