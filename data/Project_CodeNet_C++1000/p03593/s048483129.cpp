#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <numeric>

using namespace std;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define reppe(i,a,b) for(int i = (int)(a) ; i <= (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)
#define repme(i,a,b) for(int i = (int)(a) ; i >= (int)(b) ; --i)

typedef long long ll;

long long GCD(long long a, long long b){if(b==0)return a;return GCD(b,a%b);}

int main() {
    int H, W; cin >> H >> W;
    map<char, int> m;
    repp(i,0,H) {
        repp(j,0,W) {
            char c; cin >> c;
            ++m[c];
        };
    }
    bool can = true;
    
    if (H%2 == 0 && W%2 == 0) {
        for (auto x:m) can &= x.second%4 == 0;
    } else if (H%2 == 0 && W%2 == 1) {
        int count2 = 0;
        for (auto x:m) {
            if (x.second % 2 == 1) can = false;
            else if (x.second%4 == 2) ++count2;
            else can &= x.second % 4 == 0;
        }
        can &= count2 <= H / 2;
    } else if (H%2 == 1 && W%2 == 0) {
        int count2 = 0;
        for (auto x:m) {
            if (x.second % 2 == 1) can = false;
            else if (x.second%4 == 2) ++count2;
            else can &= x.second % 4 == 0;
        }
        can &= count2 <= W / 2;
    } else {
        int count1 = 0;
        int count2 = 0;
        for (auto x:m) {
            if (x.second%2 == 1) {
                ++count1;
                if (x.second > 1 && (x.second - 1) % 4 == 2) ++count2;
            } else if (x.second%4 == 2) ++count2;
            else can &= x.second % 4 == 0;
        }
        can &= (count2 <= (H + W - 2) / 2) && (count1 == 1);
    }

    if (can) cout << "Yes" << endl;
    else cout << "No" << endl;
}
