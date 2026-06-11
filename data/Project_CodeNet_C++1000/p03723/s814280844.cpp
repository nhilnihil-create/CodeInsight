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
    ll A,B,C;
    cin >> A >> B >> C;
    ll a,b,c;
    a = A;
    b = B;
    c = C;
    ll cnt = 0;
    while( a%2==0 && b%2==0 && c%2==0){
        cnt++;
        ll na,nb,nc;
        na = (b + c)/2 ;
        nb = (a + c)/2 ;
        nc = (a + b)/2 ;
        if( (na%2==0 && nb%2==0 && nc%2==0)&&((na==nb)&&(nb==nc))){
            cnt = -1;
            break;
        }
        a = na;
        b = nb;
        c = nc;
    }
    cout << cnt <<endl;
    
}
