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
#include <limits>
#include <iomanip>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    int N;
    cin >> N;
    //
    vector<int> a(N);
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    //
    vector<int> dp(100002,0);
    for(int i=0;i<N;i++){
        if(a[i]>0){
            dp[(a[i])-1]++;
            dp[a[i]]++;
            dp[(a[i])+1]++;
        }
        else{
            dp[a[i]]++;
            dp[(a[i])+1]++;
        }
    }
    //
    int max_num=0;
    int num=0;
    for(int i=0;i<dp.size();i++){
        num = dp[i];
        if(max_num < num){
            max_num = num;
        }
    }
    //
    cout << max_num << endl;
}