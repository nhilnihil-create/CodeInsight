#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl
#define INF 1000000;
#include <map>
#include <math.h>
 
using ll = long long;
using namespace std;

ll n, k;
const ll mod = 1000000007;

int disc_1(int x){
    if(x==1) return 14;
    else return x;
}

int main(){
    int a, b, max_card;
    cin >> a >> b;
    a = disc_1(a);
    b = disc_1(b);

    if(a==b) out("Draw");

    else if(a>b) out("Alice");
    else out("Bob");
}
