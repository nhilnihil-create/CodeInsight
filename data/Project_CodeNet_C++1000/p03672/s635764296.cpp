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
#include <limits>
#include <iomanip>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    string S;
    cin >> S;
    int num = S.size();
    bool frg = false;
    int max_num;
    for(int i=1;i<=num/2;i++){
        vector<char> s0((num/2)-i);
        vector<char> s1((num/2)-i);
        for(int j=0;j<(num/2)-i;j++){
            s0[j]=S[j];
            s1[j]=S[(num/2)-i+j];
        }
        if(s0==s1){
            frg = true;
            max_num = s1.size()+s0.size();
            break;
        }
    }
    cout << max_num << endl;
}