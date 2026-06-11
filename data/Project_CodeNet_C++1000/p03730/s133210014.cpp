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
    int A,B,C;
    cin >> A >> B >> C;
    vector<int>  surplus;
    for(int i=1;i<B;i++){
        int num;
        num = (A*i)%B;
        if(num>0){
        surplus.push_back(num);
        }
    }
    bool frg = false;
    for(int i=0;i<surplus.size();i++){
        if(C%surplus[i]==0){
            frg = true;
            break;
        }
    }
    if(frg){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}