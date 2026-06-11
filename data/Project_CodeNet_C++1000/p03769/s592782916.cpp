#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>

#define For(i, j, k) for(int i = j; i <= k; i++)

using namespace std;

deque<int> A, B;
int c;

void work(long long n){
	if(n == 1) return;
	if(n > 1){
		work(n >> 1);
		A.push_back(++c), B.push_back(c);
	}
	if(n & 1) A.push_back(++c), B.push_front(c);
}

long long n;

int main(){
	cin >> n;
	work(n + 1);
	int x = A.size() + B.size();
	printf("%d\n", x);
	for(int v : A) printf("%d ", v);
	for(int v : B) printf("%d ", v);
	return 0;
}