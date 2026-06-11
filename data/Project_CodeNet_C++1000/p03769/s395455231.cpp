#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<queue>
using namespace std;
typedef long long s64;

const int ONE = 100005;

int get()
{
        int res = 1, Q = 1; char c;
        while( (c = getchar()) < 48 || c > 57)
            if(c == '-') Q = -1;
        if(Q) res = c - 48;
        while( (c = getchar()) >= 48 && c <= 57)
            res = res * 10 + c - 48;
        return res * Q;
}

s64 n;
int now;
deque <int> q;

void Solve(s64 n)
{
		if(n == 1) return;
		if(n & 1) Solve(n - 1), q.push_front(++now);
		else Solve(n / 2), q.push_back(++now);
}

int main()
{
		cin >> n;
		Solve(++n);
		printf("%d\n", now << 1);
		while(!q.empty())
			printf("%d ", q.front()), q.pop_front();
		for(int i = 1; i <= now; i++)
			printf("%d ", i);
}