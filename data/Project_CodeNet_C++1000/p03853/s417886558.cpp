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
    int H,W;
    cin >> H >> W;
    vector<vector<char>> data(H+1, vector<char>(W+1));
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> data[i][j];
        }
    }
    for(int i=1;i<=2*H;i++){
        for(int j=1;j<=W;j++){
            if(j==W){
                cout << data[(i+1)/2][j] << endl;
            }
            else{
                cout << data[(i+1)/2][j];
            }
        }
    }
}