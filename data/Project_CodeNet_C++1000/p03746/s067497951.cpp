#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

int n,m;
vector <int> v[N];
deque <int> d;
int poc1,poc2;
int bio[N];

int main () {
	
	cin >> n >> m;
	for (int i = 0;i < m;i++) {
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		if (poc1 == 0) {
			poc1 = a;
		}
		if (poc2 == 0) {
			poc2 = b;
		}
	}
	
	bio[poc1] = 1;
	bio[poc2] = 1;
	
	while (1) {
		int zas = 1;
		if (d.size() == 0) {
			d.push_front(poc1);
			d.push_back(poc2);
			zas = 0;
		}
/*		cout <<"bio: ";
		for (int i = 1;i <= n;i++) {
			cout << bio[i] << " ";
		}cout << endl;
*/		
			poc1 = d.front();
			poc2 = d.back();
//			cout << "." << poc1 << endl;
			for (int i = 0;i < v[poc1].size();i++) {
//				cout << v[poc1][i] << " ";
				if (bio[v[poc1][i]]) continue;
				bio[v[poc1][i]] = 1;
				zas = 0;
				d.push_front(v[poc1][i]);
				break;		
			}//cout << endl;
//			cout << "." << poc2 << endl;
			for (int i = 0;i < v[poc2].size();i++) {
//				cout << v[poc2][i] << " ";
				if (bio[v[poc2][i]]) continue;
				bio[v[poc2][i]] = 1;
				zas = 0;
				d.push_back(v[poc2][i]);
				break;
			}
//			cout <<endl << endl;;
		if (zas == 1) break;
	}
	cout << d.size() << endl;
	for (int i = 0;i < d.size();i++) {
		cout << d[i] << " ";
	}cout << endl;
	
	
	return 0;
}