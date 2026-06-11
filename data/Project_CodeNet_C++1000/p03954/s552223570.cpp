#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <random>
#include <functional>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::map;
using std::set;
using std::bitset;
using std::vector;
using std::string;
using std::multimap;
using std::multiset;
using std::deque;
using std::queue;
using std::stack;
using std::pair;
using std::iterator;

using std::sort;
using std::stable_sort;
using std::reverse;
using std::max_element;
using std::min_element;
using std::unique;
using std::ios_base;
using std::swap;
using std::fill;

using std::setprecision;
using std::fixed;

using std::complex;

long long min(long long a, long long b) {return a < b ? a : b;}
long long min(int a, long long b) {return a < b ? a : b;}
long long min(long long a, int b) {return a < b ? a : b;}
long long min(int a, int b) {return a < b ? a : b;}

long long max(long long a, long long b) {return a > b ? a : b;}
long long max(int a, long long b) {return a > b ? a : b;}
long long max(long long a, int b) {return a > b ? a : b;}
long long max(int a, int b) {return a > b ? a : b;}

#define int long long

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef string S;
typedef complex<double> cd;

#define F(i, n) for (int (i) = 0; (i) != (n); (i)++)
#define fi first
#define se second
#define re return
#define all(x) (x).begin(), (x).end()

int n, N;
int a[500000];
int b[500000];
int c[500000];

void kek()
{
    fill(c, c + N, -1);
    c[0] = b[0], c[N - 1] = b[N - 1];
    for (int i = 0; i + 1 < N; i++)
    {
        if (b[i] == b[i + 1])
        {
            c[i] = b[i], c[i + 1] = b[i + 1];
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (c[i] == -1)
        {
            int j = i;
            while (c[j + 1] == -1) j++;
            if (i % 2 == j % 2)
            {
                for (int k = i; k <= j; k++) c[k] = c[i - 1];
            }
            else
            {
                int m = (i + j) / 2;
                for (int k = i; k <= m; k++) c[k] = c[i - 1];
                for (int k = m + 1; k <= j; k++) c[k] = c[j + 1];
            }
            i = j;
        }
    }
}

signed main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    N = 2 * n - 1;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = N + 1;
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        for (int i = 0; i < N; i++)
        {
            if (a[i] >= mid) b[i] = 1;
            else b[i] = 0;
        }
        kek();
        //cout << mid << endl;
        //for (int i = 0; i < N; i++) cout << c[i] << " ";
        //cout << endl;
        if (c[n - 1] == 1)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << l;
}
