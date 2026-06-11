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
    vector<int> a(N+1);
    for(int i=1;i<=N;i++){
        cin >> a[i];
    }
    bool frg = false;
    int num;
    int cnt;
    for(int i=0;i<=N;i++){
        if(i==0){
            num=1;
        }
        else{
            num = a[num];
            cnt++;
            if(num==2){
                frg = true;
                break;
            }
        }
    }
    if(frg){
        cout << cnt << endl;
    }
    else{
        cout << -1 << endl;
    }
}