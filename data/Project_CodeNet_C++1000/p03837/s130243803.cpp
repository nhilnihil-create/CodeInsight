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
    int N, M;
    cin >> N >> M;
    vector<vector<Edge>> edges(N + 1, vector<Edge>());

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        /*int from = min(a, b);
        int to = max(a, b);
        edges[from].emplace_back(to, c);*/
        edges[a].emplace_back(b, c);
        edges[b].emplace_back(a, c);
    }

    vector<vector<int>> d(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            d[i][j] = 10000000;
            if (i == j) {
                d[i][j] = 0;
            }
        }
    }
    
    int answer = 0;
    for (int s = 1; s <= N; s++) {

        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.emplace(0, s);

        while (!q.empty()) {
            auto pair = q.top();
            q.pop();

            int v = pair.second;
            if (d[s][v] < pair.first) {
                continue;
            }

            for (auto e : edges[v]) {
                if (d[s][e.to] > d[s][v] + e.cost) {
                    d[s][e.to] = d[s][v] + e.cost;
                    q.emplace(d[s][e.to], e.to);
                }
            }
        }

        for (auto e : edges[s]) {
            //cout << s << ":" << e.to << ":" << d[s][e.to] << endl;
            if (e.cost > d[s][e.to]) {
                answer++;
            }
        }
    }

    cout << answer / 2 << endl;
    return 0;
}