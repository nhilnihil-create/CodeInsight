#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

char dd[501][501];
int main(){
    int h,w,d;
    cin >> h >> w >> d;
    
    
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if((i+j)%(2*d)<d){
                if((i-j+2000*d)%(2*d)<d){
                    dd[i][j] = 'R';
                }else{
                    dd[i][j] = 'G';
                }
            }else{
                if((i-j+2000*d)%(2*d)<d){
                    dd[i][j] = 'B';
                }else{
                    dd[i][j] = 'Y';
                }
            }
        }
    }
    rep(i,h){
        rep(j,w){
            cout << dd[i][j];
        }
        cout << endl;
    }
    return 0;
}