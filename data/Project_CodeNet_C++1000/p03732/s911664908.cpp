#include <iostream>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stdlib.h>
#include <tuple>
#include <iomanip>
#include <iterator>
#include <stdio.h>
#include <fstream>
#include <time.h>
#include <bit>
#include <bitset>
#include <cstdint>
using namespace std;
const double PI = 3.14159265358979323846;
const long long int MOD = 1000000000 + 7;

struct UnionFind {
    vector<int> parent;

    UnionFind(int N) : parent(N) {
        for (int i = 0; i < N; i++) {
            parent[i] = -1;
        }
    }

    int root(int i) {
        if (parent[i] < 0) {
            return i;
        }
        return (parent[i] = root(parent[i]));
    }

    bool unite(int from, int to) {
        int rx = root(from);
        int ry = root(to);
        if (rx != ry) {
            parent[ry] += parent[rx];
            parent[rx] = ry;

            return true;
        }
        else {
            return false;
        }
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }

    int treeSize(int x) {


        return -parent[root(x)];
    }
};

long long int modpow(long long int base, long long int pow, long long int mod) {
    if (pow == 1) {
        return base;
    }
    else if (pow == 0) {
        return 1;
    }

    if (pow % 2 == 0) {
        auto temp = modpow(base, pow / 2, mod);
        return (temp * temp) % mod;
    }
    else {
        return (base * modpow(base, pow - 1, mod)) % mod;
    }
}

long long int moddiv(long long int X, long long int Y, long long int mod) {
    auto fermatDiv = modpow(Y, mod - 2, mod);

    return (X * fermatDiv) % mod;
}

long long modCombination(long long left, long long right, long long int mod) {
    long long answer = 1;
    if (left > right) {
        for (long long i = 0; i < right; i++) {
            answer = (answer * (left - i)) % mod;
            answer = moddiv(answer, (i + 1), mod);
        }
    }
    return answer;
}

bool IsPrime(long long N) {
    if (N == 1) {
        return false;
    }
    for (long long i = 2; i * i <= N; i++) {
        if (N % i == 0) {
            return false;
        }
    }


    return true;
}


vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
            
        }

        // その結果を push
        res.push_back({ a, ex });
    }

    // 最後に残った数について
    if (N != 1) res.push_back({ N, 1 });
    return res;
}

map<long long, set<long long>> cache;
set<long long> enum_divisors(long long N) {
    set<long long> res;
    for (long long i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.insert(i);

            if (cache.count(N / i) > 0) {
                auto copy = cache[N / i];
                auto copy2 = cache[N / i];
                for (auto v : res) {
                    if (v != 1) {
                        //cout << "v*" << v << endl;
                        for (auto itr = copy2.begin(); itr != copy2.end(); itr++) {
                            copy.insert(*itr * v);
                        }
                        break;
                    }
                }
                cache[N] = copy;
                return copy;
            }

            // 重複しないならば i の相方である N/i も push
            if (N / i != i) res.insert(N / i);

            
        }
    }

    cache[N] = res;
    return res;
}

long long euclid(long long a, long long b) {
    if (a > b) {
        long long temp = b;
        b = a;
        a = temp;
    }
    if (b % a == 0) {
        return a;
    }
    else {
        return euclid(a, b - a);
    }
}

long long gcd(long long a, long long b) {
    if (b > a) {
        long long temp = b;
        b = a;
        a = temp;
    }
    //cout << "a:" << a << "b:" << b << endl;
    long long c = a % b;
    if (c == 0) {
        return b;
    }
    else {
        return gcd(b, c);
    }
}


struct Edge {
    int to;
    int cost;
public:Edge(int _to, int _cost) {
    to = _to;
    cost = _cost;
}
};

int main() {
    int N, W;
    cin >> N >> W;
    vector<vector<int>> items(4, vector<int>());
    long long w1;
    int v;
    cin >> w1 >> v;
    items[0].push_back(v);

    for (int i = 1; i < N; i++) {
        int w, v;
        cin >> w >> v;
        items[w - w1].push_back(v);
    }

    for (int i = 0; i < 4; i++) {
        sort(items[i].begin(), items[i].end(), greater<int>());
    }

    int count0 = items[0].size(), count1 = items[1].size(), count2 = items[2].size(), count3 = items[3].size();

    int maxVal = 0;
    for (long long  i0 = 0; i0 <= count0; i0++) {
        int val0 = 0;
        for (int i = 0; i < i0; i++) {
            val0 += items[0][i];
        }
        for (long long  i1 = 0; i1 <= count1; i1++) {
            int val1 = 0;
            for (int i = 0; i < i1; i++) {
                val1 += items[1][i];
            }
            for (long long i2 = 0; i2 <= count2; i2++) {
                int val2 = 0;
                for (int i = 0; i < i2; i++) {
                    val2 += items[2][i];
                }
                for (long long i3 = 0; i3 <= count3; i3++) {

                    long long weight = w1 * i0 + (w1 + 1) * i1 + (w1 + 2) * i2 + (w1 + 3) * i3;

                    if (weight <= W) {

                        int val3 = 0;
                        for (int i = 0; i < i3; i++) {
                            val3 += items[3][i];
                        }

                        int val = val0 + val1 + val2 + val3;
                        if (maxVal < val) {
                            maxVal = val;
                        }
                    }
                }
            }
        }
    }

    cout << maxVal << endl;
    return 0;
}