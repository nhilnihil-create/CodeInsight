#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <deque>
#include <set>
//#include <numeric>
using namespace std;
using ll = long long;

#define no "no"
#define No "No"
#define NO "NO"
#define yes "yes"
#define Yes "Yes"
#define YES "YES"
#define next '\n'
#define sp " "
#define print(x) cout << (x)
#define println(x) cout << (x) << next
#define stop return(0)
#define rep(i, n) for(int (i) = (0); (i) < (n); (++i))
#define FOR(i, start, end) for(int (i) = (start); (i) < (end); (++i))
#define foreach(elem, _list) for(auto& (elem) : (_list))
#define view(_list) foreach(e, _list){ cout << e << sp; } cout << next
#define FAST ios::sync_with_stdio(false); cin.tie(nullptr)
#define size(s) (s).size()
#define ALL(vec) (vec).begin(), (vec).end()
#define pb(e) push_back(e)
#define INF 1e+8
#define PI acos(-1)
#define TAU PI * 2
#define EPS 0.00000001
const ll MOD = 1000000007;


int main(){
    int w, a, b;
    cin >> w >> a >> b;


    if(a <= b){
        if(b - (a + w) > 0){
            println(b - (a + w));
        }else{
            println(0);
        }
    }else{
        if(a - (b + w) > 0){
            println(a - (b + w));
        }else{
            println(0);
        }
    }
}
