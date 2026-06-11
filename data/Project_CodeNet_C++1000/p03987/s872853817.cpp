#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 200005;
const int INF = 0x3f3f3f3f;
typedef long long lld;
int n;
int a[N], l[N], r[N];
lld ans;

struct stack{
	int t;
	int dat[N];
	void clear() {
		t = 0;
	}
	void push(int x) {
		dat[++t] = x;
	}
	void pop() {
		--t;
	}
	int top() {
		return dat[t];
	}
	bool empty() {
		return (t == 0);
	}
}st;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)  scanf("%d", &a[i]);
	a[0] = a[n + 1] = -INF;
	st.push(0);
	for (int i = 1; i <= n; ++i) {
		while (a[i] < a[st.top()])  st.pop();
		l[i] = st.top();
		st.push(i);
	} 
	st.clear();
	st.push(n + 1);
	for (int i = n; i >= 1; --i) {
		while (a[i] <= a[st.top()])  st.pop();
		r[i] = st.top();
		st.push(i);
	}
	for (int i = 1; i <= n; ++i)  ans += 1ll * (i - l[i]) * (r[i] - i) * a[i];
	printf("%lld\n", ans);
	return 0;
}