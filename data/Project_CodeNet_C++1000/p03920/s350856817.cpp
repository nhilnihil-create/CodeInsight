#include "iostream"
#include "algorithm"
#include "string"
#include "vector"
#include "cmath"
#include "bitset"

#define lp(n) for (int i = 0; i < n; i++)
#define LP(n,i) for (int i = 0; i < n; i++)
#define mod 1000000007
#define sp ' '
#define intmax 2147483647
#define intmin -2147483647
#define llmax 9223372036854775807
typedef long long ll;
using namespace std;

int n;

int main(){
	cin >> n;
	lp(n) {
		if ((i + 1)*(i + 2) / 2 <= n && (i + 2)*(i + 3) / 2 > n) {
			int mem = (i + 2)*(i + 3) / 2 - n;
			LP(i+2,j) {
				if (j + 1 != mem)cout << j + 1 << endl;
			}
			return 0;
		}
	}
	return 0;
}