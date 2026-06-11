#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<iostream>
#include<algorithm>
#define m(a , b) memset(a , b , sizeof(a))
#define lowbit(x) (x & (-x))
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int maxn = 3e5 + 10;
const int inf = 1 << 30;
const int mod = 1e9 + 7;
priority_queue <LL , vector<LL> , less<LL> >q;
priority_queue <LL , vector<LL> , greater<LL> >p;
LL ma[maxn],ans;
LL num[maxn],mi[maxn];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= 3 * n ; i ++ )
		scanf("%lld", &num[i]);
	LL sum = 0;
	for(int i = 1; i <= 3 * n ; i ++){
		p.push(num[i]);
		sum += num[i];
		if(p.size() == n + 1){
			sum -= p.top();
			p.pop();
		}
		ma[i] = sum;
	}
	sum = 0;
	for(int i = 3 * n ; i > 0 ; i --){
		q.push(num[i]);
		sum += num[i];
		while(q.size() > n){
			sum -= q.top();
			q.pop();
		}
		mi[i] = sum;
	}
	ans = -1e16;
	for(int i = n; i <= 2 * n; i ++){
		//	printf("%lld %lld\n",ma[i],mi[i + 1]);
			ans = max(ans, ma[i] - mi[i + 1]);
	}
	printf("%lld\n", ans);
}