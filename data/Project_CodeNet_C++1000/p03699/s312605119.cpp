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
    int N;
    cin >> N;
    vector<int> s(N);
    ll total=0;
    for(int i=0;i<N;i++){
        cin >> s[i];
        total +=s[i];
    }

    int min=0;

    bool frg= false;
    for(int i=0;i<N;i++){
        if((s[i] % 10)!=0){
            min=s[i];
            frg = true;
            break;
        }
    }
    if(frg){
        for(int i=0;i<N;i++){
            if(((s[i]%10)!=0)&&(min > s[i])){
                min = s[i];
            }
        }
    }

    if((total%10)!=0){
        cout << total <<endl;
    }
    else{
        if(frg){
            cout << total - min << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
}