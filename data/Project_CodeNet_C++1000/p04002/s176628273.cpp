#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)
constexpr long MOD = 1e9 + 7;
using namespace std;

#include <map>

map<pair<int,int>, int> m;
long h, w, n;
long counter[10];
long nonzero = 0;

void hoge(int a, int b) {
    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (0 <= a + i && a + i < h && 0 <= b + j && b + j < w) {
                m[make_pair(a + i, b + j)]++;
            }
        }
    }
}

int main() {
    cin >> h >> w >> n;
    
    int a, b;
    
    REP(i,n) {
        cin >> a >> b;
        hoge(a-1,b-1);
    }
    
    for (auto itr = m.begin(); itr != m.end(); itr++) {
        if (itr->first.first > 0 && itr->first.first < h - 1 && itr->first.second > 0 && itr->first.second < w - 1) counter[itr->second]++;
    }
    
    for (int i = 1; i < 10; i++) nonzero += counter[i];
    
    cout << (h-2) * (w-2) - nonzero << endl;
    
    for (int i = 1; i < 10; i++) cout << counter[i] << endl;
}
