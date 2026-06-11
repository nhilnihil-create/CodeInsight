#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
#define S second
template <typename T>
struct countmap {
    std::map<T, long long> dict;
    countmap() {
        dict = map<T, long long>();
    }
    bool contains(T key) {
        return (dict.find(key) != dict.end());
    }
    long long operator[](T key) {
        if (dict.find(key) != dict.end()) {
            return dict[key];
        } else {
            return 0;
        }
    }
    void incremntFor(T key, long long inc = 1) {
        if (dict.find(key) != dict.end()) {
            dict[key] += inc;
        } else {
            dict.emplace(key, inc);
        }
    }
    auto begin() const {
        return dict.begin();
    }
    auto end() const {
        return dict.end();
    }
};
int main() {
    int n, m;
    cin >> n >> m;
    auto dict = countmap<int>();
    rep(i,2*m){
        int x;
        cin >> x;
        dict.incremntFor(x);
    }
    for(auto &p: dict){
        if(p.S %2 ==1){
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}
