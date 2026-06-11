#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int > vi;
ll gcd(ll a, ll b) {
	if (a > b)swap(a, b);
	if (b%a == 0)return a;
	return gcd(b, b%a);
}
vl gcd(vl A) {
	ll g = A[0];
	for (int i = 1; i < A.size(); i++) {
		g = gcd(g, A[i]);
	}
	
	for (int i = 0; i < A.size(); i++) {
		A[i] /= g;
	}
	return A;
}
int numofeven(const vl&  A) {
	int n = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] % 2 == 0)n++;
	}
	return n;
}
ostream& operator<<(ostream& os,const vl& A) {
	for (int i = 0; i < A.size(); i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	return os;
}
bool isfirst(vl A) {
//	cout << A;
	int noe = numofeven(A);
	int noo = A.size() - noe;
	if (noe % 2 == 1)return true;
	else if (noo>1)return false;	
	else {
		for (int i = 0; i < A.size(); i++) {
			if (A[i] % 2 == 1) {
				if (A[i] == 1)return false;
				else {
					A[i]--;
					break;
				}
			}
		}
		A=gcd(A);
		return !isfirst(A);
	}
}

int main() {
	int n;
	cin >> n;
	vl A(n);
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	if (isfirst(A)) {
		cout << "First" << endl;
	}
	else {
		cout << "Second" << endl;
	}
	return 0;
}