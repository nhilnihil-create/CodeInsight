#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <math.h>
#include <iomanip>
using namespace std;
#define int long long

int gcd(int a,int b){
    return b ? gcd(b, a % b) : a;
}
int lcm(int a,int b){
    return b / gcd(a,b) * a;
}


signed main(){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    string sa,sb,sc; cin >> sa >>sb  >> sc;
    reverse(sa.begin(),sa.end());
    reverse(sb.begin(),sb.end());
    reverse(sc.begin(),sc.end());

    char now = 'a';

    for(;;){
        if(now == 'a'){
            if(sa.size() == 0){
                cout << 'A' << endl;
                return 0;
            }
            now = sa.at(sa.size()-1);
            sa.pop_back();
        }else if(now == 'b'){
            if(sb.size() == 0){
                cout << 'B' << endl;
                return 0;
            }
            now = sb.at(sb.size()-1);
            sb.pop_back();            
        }else{
            if(sc.size() == 0){
                cout << 'C' << endl;
                return 0;
            }
            now = sc.at(sc.size()-1);
            sc.pop_back();
        }

    }
}