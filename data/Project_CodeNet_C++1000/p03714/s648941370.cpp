#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>

#define REP(i, n) for(int (i)=0;(i)<(n);++(i))
#define MOD 1000000007

typedef long long ll;

using namespace std;
int main(){
    int N;
    cin >> N;
    vector<ll> a;
    REP(i, 3 * N)
    {
    	ll t;
    	cin >> t;
    	a.push_back(t);
    }

    ll sum_front[N + 1] = { 0 };
    priority_queue<ll, vector<ll>, std::greater<ll>> que_front;
    // a[0] ~ a[N - 1] を優先度付きキューに追加
   	for (int i = 0; i < N; ++i)
    {
    	que_front.push(a[i]);
    	sum_front[0] += a[i];
    }
    
    for(int k = 1; k <= N; ++k)
    {
    	que_front.push(a[N - 1 + k]);
    	ll min_element = que_front.top();
    	que_front.pop();
    	sum_front[k] = sum_front[k - 1] + a[N - 1 + k];
    	sum_front[k] -= min_element;

    }

    ll sum_back[N + 1] = { 0 };
    priority_queue<ll> que_back;
    // a[2 * N] ~ a[3 * N -1] を優先度付きキューに追加
   	for (int i = 0; i < N; ++i)
    {
    	que_back.push(a[2 * N + i]);
    	sum_back[N] += a[2 * N + i];
    }

    for (int k = 1; k <= N; ++k)
    {
    	que_back.push(a[2 * N - k]);
    	ll max_element = que_back.top();
    	que_back.pop();
    	sum_back[N - k] = sum_back[N - k + 1] + a[2 * N - k];
    	sum_back[N - k] -= max_element;
    }

    ll diff_max = sum_front[0] - sum_back[0];
    for(int k = 1; k <= N; ++k)
    {
    	ll diff = sum_front[k] - sum_back[k];
    	diff_max = max(diff_max, diff);
    }

    cout << diff_max << endl;
}
