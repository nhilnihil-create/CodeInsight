#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    ll a,b;
    cin >> a >> b;
    ll ans ;
    if(a*b<=0){
        cout << "Zero" << endl;
    }
    //  ( a > 0 && b > 0 ) || ( a < 0 && b < 0)
    else if(a > 0 && b > 0){
        cout << "Positive" << endl;
    }
    else if(a < 0 && b < 0){
        int num = b -a + 1;
        if(num%2==0){
            cout << "Positive" << endl;
        }
        else{
            cout << "Negative" << endl;
        }
    }
}