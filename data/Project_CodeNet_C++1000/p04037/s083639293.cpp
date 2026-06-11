#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 410


int main() {
	vector<int>a;
	vector<int>b;
	int n, x;
	scanf("%d", &n);
	f(i, n) {
		scanf("%d", &x);
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	f(i, n) {
		if (i > 0) {
				if ((a[i] - a[i-1]) % 2 == 0) {
					b.push_back(((b[b.size() - 1] + 1) % 2));
					if (b.size() >= n) {
						if (b[n - 1] == 1)printf("Second\n");
						else printf("First\n");
						return 0;
					}
					f(j, a[i] - a[i-1]) {
						if (j % 2 == 0)b.push_back(0);
						else b.push_back(1);
						if (b.size() >= n) {
							if (b[n - 1] == 1)printf("Second\n");
							else printf("First\n");
							return 0;
						}
					}
				}
				else {
					b.push_back(0);
					if (b.size() >= n) {
						if (b[n - 1] == 1)printf("Second\n");
						else printf("First\n");
						return 0;
					}
					f(j, a[i] - a[i-1]) {
						if (j % 2 == 0)b.push_back(1);
						else b.push_back(0);
					if (b.size() >= n) {
						if (b[n - 1] == 1)printf("Second\n");
						else printf("First\n");
						return 0;
					}
				}

				}
         }
		else {
			if (a[i] % 2 == 0) {
				f(j, a[i]) {
					if (j % 2 == 0)b.push_back(0);
					else b.push_back(1);
					if (b.size() >= n) {
						if (b[n - 1] == 1)printf("Second\n");
						else printf("First\n");
						return 0;
					}
				}
			}
			else {
				f(j, a[i]) {
					if (j % 2 == 0)b.push_back(1);
					else b.push_back(0);
				if (b.size() >= n) {
					if (b[n - 1] == 1)printf("Second\n");
					else printf("First\n");
					return 0;
				}
			}
			}
		}
	}

	return 0;
}