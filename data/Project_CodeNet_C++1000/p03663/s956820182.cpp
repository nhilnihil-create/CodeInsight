#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <complex>
#include <set>
#include <list>
#include <iomanip>
#include <map>
#include <functional>
#include <string.h>

using namespace std;
static const double EPS = 1e-9;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a,0,sizeof(a))
#define minus(a) memset(a,0xff,sizeof(a))
#define chmax(a,b) a=min((a),(b))
#define chmin(a,b) a=max((a),(b))


#define MOD 1000000007

typedef pair<int,int>P;
#define INF (1<<29)
 
struct edge{
	int dst;
	ll cost;
	edge(int dst, ll cost){
		this->dst=dst; this->cost=cost;
	}

};


 
int V,E;
typedef vector<edge> edges;
vector<edges> g;

ll num = 1000000000;//
char ans;

void print(ll num) {
	cout << "? " << num << endl;
}
void printout(ll num) {
	cout << "! " << num << endl;
}

void func1() {
	num = 2;
	while (1) {
		print(num);
		cin >> ans;
		if (ans == 'Y') {
			printout(num / 2);
			exit(1);
		}
		else {
			num *= 10;
		}
	}
}

void func3() {
	ll l = num;
	ll r = num * 10;
	ll m;
	while (r - l>1) {
		m = (l + r) / 2;
		print(m*10);
		cin >> ans;

		if (ans == 'Y') {
			r = m;
		}
		else {
			l = m;
		}
	}
	printout(r);//
	exit(1);
}

void func2() {
	num /= 10;//
	while (1) {
		print(num);
		cin >> ans;

		if (ans == 'Y') {
			func3();
		}
		else {
			num /= 10;
		}
	}
}


int main(){

	print(num);
	while (1) {
		scanf("%c", &ans);
		if (ans == 'Y') {
			func1();
		}
		else {
			func2();
		}
	}

	return 0;
}
