#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>
#include <fstream>
#include <functional>
#define endl '\n'
#define ll long long
#define mod 1000000007
#define NCONS 200001
//#define NCONS 100001
//#define NCONS 1001
//#define NCONS 101
#define MCONS 2001
#define LIMIT 1000000000
#define TRUE 1
#define FALSE 0
#define toRadian(degree) ((degree) * (M_PI / 180.))
#define toDegree(radian) ((radian) * (180. / M_PI))
using namespace std;
struct Point{int x; int y;};
struct PPoint{Point x; Point y;};
ll gcd(ll a, ll b) { if(a < b) swap(a, b); if(b <= 0) return a; return gcd(b, a % b); }

int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    ll N; cin >> N;
    ll acc = 0;
    ll counter = 1;
    while(acc < N)
    {
        acc += counter;
        counter++;
    }
    
    for(ll i = 1; i < counter; i++)
    {
        if(i == acc - N) continue;
        cout << i << endl;
    }

    return 0;
}
