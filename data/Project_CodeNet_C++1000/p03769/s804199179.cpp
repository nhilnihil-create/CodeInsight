#include <cstdio>
#include <deque>

using namespace std;

deque<int> q1, q2;
int ans = 0;

void fun(long long n){
	if(n == 1)
		return;
	fun(n >> 1);
	ans++;
	q1.push_front(ans);
	q2.push_front(ans);
	if(n & 1){
		ans++;
		q1.push_front(ans);
		q2.push_back(ans);
	}
	return;
}

int main(){
	long long n;
	scanf("%lld", &n);
	fun(n + 1);
	printf("%d\n", q1.size() + q2.size());
	while(!q1.empty()){
		printf("%d ", q1.front());
		q1.pop_front();
	}
	while(!q2.empty()){
		printf("%d ", q2.front());
		q2.pop_front();
	}
	return 0;
} 