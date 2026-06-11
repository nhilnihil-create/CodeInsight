#include <cstdio>
#include <vector>
int main() {
	long long n;
	scanf("%lld", &n);
	n++;
	
	int all = 100;
	
	std::vector <int> p, q;
	while(n > 1) {
		if(n & 1) {
			p.push_back(all--);
			n--;
		}
		else {
			q.push_back(all--);
			n >>= 1;
		}
	}
	
	int sz = p.size() + q.size();
	printf("%d\n", sz + 100);
	for(int i = 0; i < p.size(); i++)
		printf("%d ", p[i]);
	for(int i = q.size() - 1; ~i; --i)
		printf("%d ", q[i]);
	for(int i = 1; i <= 100; i++)
		printf("%d ", i);
	return 0;
}