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
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> x(N+1);
    x[0]=0;
    int max=0;
    for(int i=0;i<N;i++){
        if(S[i]=='I'){
            x[i+1]=x[i] + 1;
        }
        else if(S[i]=='D'){
            x[i+1]=x[i] - 1;
        }
        if(x[i+1]>max){
            max = x[i+1];
        }
    }
    cout << max << endl;
}