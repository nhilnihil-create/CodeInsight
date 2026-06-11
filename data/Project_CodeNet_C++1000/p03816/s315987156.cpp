#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <numeric>
#include <algorithm>
#include <utility>


using std::cout;
using std::cin;
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


ll gcd(ll a, ll b) {
    while (b != 0) {
        auto tmp = a;
        a = b;
        b = tmp % a;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return (a * b) / gcd(a, b);
}

int isPrime(int a) {
    for (int i = 2; i * i <= a; ++i) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}




void oneCase () {
    int n;
    cin >> n;
    map<int, int> counter;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ++counter[a];
    }
    priority_queue<int> heap;
    for (auto it : counter) {
        heap.emplace(it.second);
    }
    while (true) {
        if (heap.top() == 1) {
            break;
        }
        auto count = heap.top();
        heap.pop();
        if (count < 2) {
            heap.push(count - 2);
        } else {
            if (heap.empty()) {
                cout << 1 << "\n";
                return;
            }
            auto count2 = heap.top();
            heap.pop();
            heap.push(count - 1);
            if (count2 > 1) {
                heap.push(count2 - 1);
            }
        }
    }
    cout << heap.size() << "\n";
}





int main() {
    int t = 1;
//    cin >> t;
    while (t > 0) {
        oneCase();
        --t;
    }

    return 0;
}