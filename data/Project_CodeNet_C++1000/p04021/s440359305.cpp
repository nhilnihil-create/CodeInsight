#include<bits/stdc++.h>
using namespace std;

int x,y,z,n,m;
char tmp;
pair<int,int> ar[100005];
string s1,s2;

int main() {
	cin >> x;
	for (int i = 0; i < x; i++) {
		cin >> ar[i].first;
		ar[i].second = i;		
	}
	stable_sort(ar,ar+x);
	for (int i = 0; i < x; i++) {
		if (ar[i].second%2 != i%2) {
			n++;
		}
	}
	cout << n/2;
}