#define _USE_MATH_DEFINES
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <clocale>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

const int MOD = 1000000007; 
const int INF = 1000000000; //1e9
const int NIL = -1;
const long long LINF = 1000000000000000000; // 1e18
const double EPS = 1E-10;

template<class T, class S>
bool chmax(T &a, const S &b){
    if(a < b){
        a = b; return true;
    }
    return false;
}
template<class T, class S>
bool chmin(T &a, const S &b){
    if(b < a){
        a = b; return true;
    }
    return false;
}



int main(){
    int H, W; std::cin >> H >> W;
    std::vector<int> cnt(26, 0);
    {
        std::string a;
        for(int i(0); i < H; ++i){
            std::cin >> a;
            for(int j(0); j < W; ++j){
                ++cnt[a[j]-'a'];
            }
        }
    }
    int cnt1(0), cnt2(0);
    for(int i(0); i < 26; ++i){
        if(cnt[i] % 2){
            ++cnt1; --cnt[i];
        }
        if(!(cnt[i] % 2) && (cnt[i] % 4)) ++cnt2;
    }
    bool okay(true);
    int lim1((H % 2) & (W % 2)), lim2(0);
    if(H % 2) lim2 += W / 2;
    if(W % 2) lim2 += H / 2;
    if(cnt1 > lim1) okay = false;
    if(cnt2 > lim2) okay = false;
    std::cout << (okay ? "Yes" : "No") << std::endl;
    return 0;
}
