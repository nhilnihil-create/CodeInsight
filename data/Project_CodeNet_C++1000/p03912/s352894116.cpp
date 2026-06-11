#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define llong long long
#define INF (__INT32_MAX__ / 2)
#define EPS 10e-8
#define MAX_NMX 100000

using namespace std;
typedef pair<llong, llong> ipair;
llong modulo(llong left, llong right) { return (left % right + right) % right; }

int N, M, X[MAX_NMX];

int numbers[MAX_NMX + 1];
int not_paired[MAX_NMX];
int pairs[MAX_NMX];


int solve() {
    for(int i = 0; i < N; ++i)
        numbers[X[i]]++;

    for(int i = 0; i <= MAX_NMX; ++i) {
        pairs[i % M] += numbers[i] / 2;
        if(numbers[i] % 2 == 1)
            not_paired[i % M]++;
    }

    int res = 0;
    for(int i = 0; i * 2 <= M; ++i)
        if(i == 0 || i * 2 == M) {
            res += not_paired[i] / 2;
        } else {
            
            if(not_paired[i] > not_paired[M - i]) { 
                int carry = min(not_paired[i] - not_paired[M - i], 2 * pairs[M - i]);
                res += not_paired[M - i] + carry;
                pairs[M - i] = (2 * pairs[M - i] - carry) / 2;

            } else if(not_paired[i] < not_paired[M - i]) { 
                int carry = min(not_paired[M - i] - not_paired[i], 2 * pairs[i]);
                res += not_paired[i] + carry;
                pairs[i] = (2 * pairs[i] - carry) / 2;

            } else {
                res += not_paired[i];
            }
        }

    for(int i = 0; i < M; ++i)
        res += pairs[i];

    return res;
}

int main(int argc, char **argv) {
    cin >> N >> M;
    for(int i = 0; i < N; ++i)
        cin >> X[i];

    cout << solve() << endl;   
}