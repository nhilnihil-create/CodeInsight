#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
using namespace std;
#define endl '\n'
#define ll long long
#define pi pair<int, int>
#define f first
#define s second
#define sq(x) ((x) * (x))

const int mxn = 501;
int n;
int a[sq(mxn)];
pi p[mxn];

void die(){
	cout << "No" << endl;
	exit(0);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	memset(a, -1, sizeof(a));
	for(int i = 0; i < n; i++){
		cin >> p[i].f;
		a[--p[i].f] = p[i].s = i;
	}
	
	sort(p, p + n);
	
	int x = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < p[i].s; j++){
			while(~a[x]) x++;
			a[x] = p[i].s;
		} 
		if(x > p[i].f) die();
	}
	
	for(int i = 0; i < n; i++){
		while(~a[x]) x++;
		if(x < p[i].f) die();
		for(int j = 0; j < n - p[i].s - 1; j++){
			while(~a[x]) x++;
			a[x] = p[i].s;
		}
	}
	
	cout << "Yes" << endl;
	cout << a[0] + 1;
	for(int i = 1; i < sq(n); i++) cout << " " << a[i] + 1;
	cout << endl;

	return 0;
}