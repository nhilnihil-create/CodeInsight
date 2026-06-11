#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"
#include "queue"
#include "functional"
#include "map"
#include "unordered_map"

#define lp(n) for (int i = 0; i < n; i++)
#define LP(n,i) for (int i = 0; i < n; i++)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define llmax 9223372036854775807
#define nya_n "(=^･ω･^=)"
typedef long long ll;
using namespace std;


int n, p, cnt;
bool flag;

int main() {
	flag = false;
	cnt = 0;
	cin >> n;
	lp(n) {
		cin >> p;
		if (p == i + 1) {
			if (!flag)
				cnt++;
			flag = !flag;
		}
		else flag = false;
	}
	cout << cnt << endl;
	return 0;
}