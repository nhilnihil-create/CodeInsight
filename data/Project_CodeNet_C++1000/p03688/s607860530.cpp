// #include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <limits.h>
#include <string>
#include <stack>
#include <deque>
#include <cmath>
#include <bitset>
#include <complex>
#include <functional>
#include <time.h>
#include <cassert>
#include <fstream>
#include <stdio.h>
#include<unordered_map>

typedef long long ll;
typedef std::pair<int, int> Pii;
typedef std::pair<long long, long long> Pll;
typedef std::pair<double, double> Pdd;

#define rip(i, n, s) for (int i = (s);i < (int)( n ); i++)
#define mapa make_pair
#define all(a) a.begin(), a.end()
#define MM << " " <<

template<typename T>
using MaxHeap = std::priority_queue<T>;
template<typename T>
using MinHeap = std::priority_queue<T, std::vector<T>, std::greater<T>>;

template<typename T>
inline bool chmax(T &a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}
template<typename T>
inline bool chmin(T &a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }
template<typename T>
void vdeb(std::vector<T> &da) {
	for (int i = 0;i < da.size();i++) {
		if (i == da.size() - 1) std::cout << da[i];
		else std::cout << da[i] << ' ';
	}
	std::cout << std::endl;
}
template<typename T>
void vdeb(std::vector<std::vector<T>> &da) {
	for (int i = 0;i < da.size();i++) vdeb(da[i]);
	std::cout << std::endl;
}

using namespace std;

bool solve(){
	int n; cin >> n;
	vector<int> da(n);
	rip(i,n,0) cin >> da[i];
	map<int, int> mp;
	rip(i,n,0){
		if(mp.count(da[i])) ++mp[da[i]];
		else mp[da[i]] = 1;
	}
	if(mp.size() > 2) return false;
	if(mp.size() == 1 && (*mp.cbegin()).first == n-1) return  true;
	Pii a = *mp.cbegin(), b = *(--mp.cend());
	if(mp.size() == 1) --a.first, a.second = 0;
	if(b.first - a.first != 1 || b.first <= a.second) return false;
	// cout << a.first MM a.second MM b.first MM b.second << endl;
	return n - a.second >= (b.first-a.second)*2 && b.first <= n;
}

int main(){
	printf((solve())?"Yes\n":"No\n");
}