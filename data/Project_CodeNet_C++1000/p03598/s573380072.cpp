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
    int N, K;
    cin >> N >> K;
    //
    vector<int> x(N);
    for(int i=0;i<N;i++){
        cin >>x[i] ;
    }
    //
    long long distance = 0;
    for(int i=0;i<N;i++){
        int shortest ;
        if( abs(x[i]-0) < abs(x[i] -K)){
            shortest = abs(x[i]- 0);
        }
        else {
            shortest = abs(x[i]- K);
        }
        distance = distance + shortest*2 ;
    }
    cout << distance << endl;

}