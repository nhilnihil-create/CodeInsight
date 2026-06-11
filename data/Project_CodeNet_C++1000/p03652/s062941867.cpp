#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>
 
using namespace std;
 
#define mod 1000000007
 
int n, m;
int a[301][301];
 
int solve(set<int> s)
{
	if(s.empty()) return n;
	int cnt[301] = {};
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(s.find(a[i][j]) != s.end()){
				cnt[a[i][j]]++;
				break;
			}
		}
	}
	int maxcnt = *max_element(cnt, cnt + m);
	int ans = maxcnt;
	for(auto itr = s.begin(); itr != s.end(); itr++){
		if(cnt[*itr] == maxcnt){
			s.erase(*itr);
			ans = min(ans, solve(s));
            return ans;
		}
	}
}
 
int main()
{
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			a[i][j]--;
		}
	}
 
	set<int> s;
	for(int i = 0; i < m; i++){
		s.insert(i);
	}
	cout << solve(s) << endl;
}