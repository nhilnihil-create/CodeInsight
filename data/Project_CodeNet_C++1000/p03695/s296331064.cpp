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
    vector<int> rate(N);
    for(int i=0;i<N;i++){
        cin >> rate[i];
    }
    vector<int> colors(9);
    int color_max=0;
    int color_min=0;
    for(int i=0;i<N;i++){
        if(rate[i]<=399){
            colors[0]++;
        }
        else if(rate[i]<=799){
            colors[1]++;
        }
        else if(rate[i]<=1199){
            colors[2]++;
        }
        else if(rate[i]<=1599){
            colors[3]++;
        }
        else if(rate[i]<=1999){
            colors[4]++;
        }
        else if(rate[i]<=2399){
            colors[5]++;
        }
        else if(rate[i]<=2799){
            colors[6]++;
        }
        else if(rate[i]<=3199){
            colors[7]++;
        }
        else if(rate[i]<=4800){
            colors[8]++;
        }
    }
    for(int i=0;i<8;i++){
        if(colors[i]>0){
            color_min++;
        }
    }
    color_max = color_min + colors[8];
    if(color_min==0&&colors[8]>0){
        color_min=1;// colors[8]>0であるとき
    }
    cout << color_min << " " << color_max << endl;
}