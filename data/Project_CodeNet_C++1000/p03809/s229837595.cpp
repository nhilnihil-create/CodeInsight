#define _CRT_SECURE_NO_WARNINGS
#pragma target("avx")
#pragma optimize("O3")
#pragma optimize("unroll-loops")
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define rep(i,n) for(int i=0;i<(lint)(n);i++)
#define REP(i,n) for(int i=1;i<=(lint)(n);i++)
#define all(V) V.begin(),V.end()
typedef long long lint;
typedef std::pair<lint, lint> P;
constexpr int INF = INT_MAX/2;
constexpr lint LINF = LLONG_MAX/2;
constexpr double eps = 1e-9;
template<class T>
class prique :public std::priority_queue<T, std::vector<T>, std::greater<T>> {};
template <class T, class U>
inline bool chmax(T& lhs, const U& rhs) {
	if (lhs < rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
template <class T, class U>
inline bool chmin(T& lhs, const U& rhs) {
	if (lhs > rhs) {
		lhs = rhs;
		return 1;
	}
	return 0;
}
inline lint gcd(lint a, lint b) {
	while (b) {
		lint c = a;
		a = b; b = c % b;
	}
	return a;
}
inline lint lcm(lint a, lint b) {
	return a / gcd(a, b) * b;
}
bool isprime(lint n) {
	if (n == 1)return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0)return false;
	}
	return true;
}
lint mypow(lint a, lint b) {
	if (!b)return 1;
	if (b & 1)return mypow(a, b - 1) * a;
	lint memo = mypow(a, b >> 1);
	return memo * memo;
}
lint modpow(lint a, lint b, lint m) {
	if (!b)return 1;
	if (b & 1)return modpow(a, b - 1, m) * a % m;
	lint memo = modpow(a, b >> 1, m);
	return memo * memo % m;
}
template<typename T>
void printArray(std::vector<T>& vec) {
	rep(i, vec.size() - 1)std::cout << vec[i] << " ";
	std::cout << vec.back() << std::endl;
}
template<typename T>
void printArray(T l, T r) {
	T rprev = r;
	rprev--;
	for (T i = l; i != rprev; i++) {
		std::cout << *i << " ";
	}
	std::cout << *rprev << std::endl;
}
std::string to_string(std::vector<int>& vec) {
	std::string res = "[";
	rep(i, vec.size() - 1)res += std::to_string(vec[i]) + ", ";
	res += std::to_string(vec.back()) + "]";
	return res;
}
int n,a[100010],memo[100010],deg[100010];
std::vector<int> vec[100010];
bool used[100010];
int main(){
	std::cin>>n;
	REP(i,n){
		std::cin>>a[i];
		memo[i]=a[i];
	}
	rep(i,n-1){
		int u,v;
		std::cin>>u>>v;
		vec[u].push_back(v);
		vec[v].push_back(u);
		deg[u]++;deg[v]++;
	}
	std::queue<int> que;
	REP(i,n){
		if(deg[i]==1){
			que.push(i);
		}
		else a[i]*=2;
	}
	while(!que.empty()){
		int node=que.front();
		que.pop();
		used[node]=true;
		if(deg[node]==0&&a[node]||memo[node]<a[node]){
			puts("NO");
			return 0;
		}
		for(int i:vec[node]){
			if(!used[i]){
				a[i]-=a[node];
				if(memo[i]<a[node]){
					puts("NO");
					return 0;
				}
				if(a[i]<0){
					puts("NO");
					return 0;
				}
				deg[i]--;
				if(deg[i]==1)que.push(i);
			}
		}
	}
	puts("YES");
	return 0;
}
