#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
#include <chrono>
#include <random>
#include <tuple>
#include <utility>

const int INF = 1000000009;
const long LINF = 1123456789012345678;

std::set<long> st;
std::deque<long> deq;

long n, m;
std::vector<long> path[100005];

void push(bool front, long a){
	st.insert(a);
	if(front){
		deq.push_front(a);
	}else{
		deq.push_back(a);
	}
	return;
}

void check(bool front, long a){
	for(int i = 0; i < path[a].size(); i++){
		long nx = path[a][i];
		if(st.count(nx) == 0){
			push(front, nx);
			check(front, nx);
			return;
		}
	}
	return;
}

int main(){
	scanf("%ld %ld", &n, &m);
	for(int i = 0; i < m; i++){
		long a, b;
		scanf("%ld %ld", &a, &b);
		path[a].push_back(b);
		path[b].push_back(a);
	}
	push(true, 1);
	push(false, path[1][0]);
	check(true, 1);
	check(false, path[1][0]);
	printf("%ld\n", deq.size());
	for(auto it = deq.begin(); it != deq.end(); it++){
		printf("%ld ", *it);
	}
	printf("\n");
	return 0;
}
