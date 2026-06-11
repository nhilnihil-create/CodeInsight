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
    //
    vector<int> time(N);
    for(int i=0;i<N;i++){
        cin >> time[i];
    }
    //
    int M;
    cin >> M;
    for(int i=0;i<M;i++){
        int total__time=0;
        int P,X;
        cin >> P>> X;
        for(int j=0;j<N;j++){
            if(j==(P-1)){
                total__time += X;
            }
            else{
                total__time += time[j];
            }
        }
        cout << total__time << endl;
    }
}