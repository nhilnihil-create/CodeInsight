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
    int H ,W;
    cin >> H >> W;
    vector<vector<char>> data(H+2, vector<char>(W+2));
    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> data[i][j];
        }
    }
    //
    for(int i=0;i<=H+1;i++){
        for(int j=0;j<=W+1;j++){
            if((i==0)||(i==H+1)){
                data[i][j]='#';
            }
            else if((j==0)||(j==W+1)){
                data[i][j]='#';
            }
        }
    }
    //
    for(int i=0;i<=H+1;i++){
        for(int j=0;j<=W+1;j++){
            if(j!=W+1){
                cout << data[i][j] ;
            }
            else{
                cout << data[i][j] << endl;
            }
        }
    }
}