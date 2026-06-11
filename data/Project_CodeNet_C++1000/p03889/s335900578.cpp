#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << (x) << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
int main(){
    string s;
    cin >> s;
    bool flag = true;
    int n = (int)s.size();
    auto ss = s;
    reverse(ss.begin(),ss.end());
    rep(i,n){
        if(ss[i] == 'b') ss[i] = 'd';
        else if(ss[i] == 'p') ss[i] = 'q';
        else if(ss[i] == 'd') ss[i] = 'b';
        else if(ss[i] == 'q') ss[i] = 'p';
    }
    if(s == ss){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}