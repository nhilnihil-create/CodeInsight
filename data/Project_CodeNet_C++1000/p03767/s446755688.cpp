#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    int N;
    cin >> N;
    vector<int> a(3*N);
    for(int i=0;i<3*N;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    ll max=0;
    for(int i=0;i<N;i++){
        max += a[3*N-1-(2*i+1)];
    }
    cout << max << endl;
}