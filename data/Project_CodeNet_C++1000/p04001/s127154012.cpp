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
using namespace std;

int times(long x, int n){
    if(x < 10){
        n++;
        return n;
    }
    return times(x / 10, n + 1);
}

long sum(vector<long> &num, vector<int> &plus, int n){
    long ans = 0;
    long sump = 0;
    if (n == 0){
        sump = num.at(0);
        for(int i = 0; i < plus.size(); i++){
            if (plus.at(i) == 0){
                sump *= 10;
                sump += num.at(i + 1);
            }
            else{
                ans += sump;
                sump = num.at(i + 1);
            }
        }
        ans += sump;
        return ans;
    }
    if (n > 0){
        plus.at(plus.size() - n) = 0;
        long i = sum(num, plus, n - 1);
        ans += i;
        plus.at(plus.size() - n) = 1;
        i = sum(num, plus, n - 1);
        ans += i;
        return ans;
    }
}

int main() {
    string S;
    cin >> S;
    long s = stol(S);
    int n = times(s, 0);
    vector<long> num(n);
    for (int i = n - 1; i > -1; i--){
        num.at(i) = s % 10;
        s /= 10;
    }
    vector<int> plus(n - 1, 0);
    int a = plus.size();
    long ans = sum(num, plus, a);
    cout << ans << endl;
}