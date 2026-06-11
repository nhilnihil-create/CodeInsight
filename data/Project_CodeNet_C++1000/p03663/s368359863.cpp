#include "bits/stdc++.h"
using namespace std;

#define DEBUG(x) cout<<#x<<": "<<x<<endl;
#define DEBUG_VEC(v) cout<<#v<<":";for(int i=0;i<v.size();i++) cout<<" "<<v[i]; cout<<endl

typedef long long ll;
#define vi vector<int>
#define vl vector<ll>
#define vii vector< vector<int> >
#define vll vector< vector<ll> >
#define vs vector<string>
#define pii pair<int,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define pll pair<ll,ll>
const int inf = 1000000001;
const ll INF = 2e18 * 2;
#define MOD 1000000007
#define mod 1000000009
#define pi 3.14159265358979323846
#define Sp(p) cout<<setprecision(15)<< fixed<<p<<endl;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };

void ask(string s) {
	cout << "? " << s << endl;
	return;
}

void ask(ll s) {
	cout << "? " << s << endl;
	return;
}

int main() {
	string ques = "999999999999999";
	bool isfirst = true;
	int i, j;
	for (i = 0; i < 10; i++) {
		if (!isfirst) {
			ques[i] = '0';
			ask(ques);
			char res;
			scanf(" %c", &res);
			if (res == 'Y') {
				continue;
			}
		}
		else {
			isfirst = false;
		}

		int left = 0, right = 9;
		while (left + 1 < right) {
			int mid = (left + right) / 2;
			ques[i] = mid + '0';
			ask(ques);
			char res;
			scanf(" %c", &res);
			if (res == 'Y') {
				right = mid;
			}
			else {
				left = mid;
			}
		}
		ques[i] = right + '0';
	}
	ques = ques.substr(0, 10);
	for (i = 9; i >= 0; i--) {
		if (ques[i] != '0') {
			break;
		}
	}
	int left = i;
	bool nine = true;
	for (i = 0; i <= left; i++) {
		if (ques[i] != '9') {
			nine = false;
		}
	}

	for (i = 10; i >= left + 1; i--) {
		string s = ques.substr(0, i);
		ll temp = stoll(s);
		temp += 1;
		ask(temp);
		char res;
		scanf(" %c", &res);
		if (i != left + 1) {
			if (res == 'N') {
				cout << "! " << ques.substr(0, i + 1) << endl;
			}
		}
		else {
			if (!nine) {
				if (res == 'N') {
					cout << "! " << ques.substr(0, i + 1) << endl;
				}
				else {
					cout << "! " << ques.substr(0, i) << endl;
				}
			}
			else {
				if (res == 'N') {
					cout << "! " << ques.substr(0, i) << endl;
				}
				else {
					cout << "! " << ques.substr(0, i + 1) << endl;
				}
			}
		}
	}
}