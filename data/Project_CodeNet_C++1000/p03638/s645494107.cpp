#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <math.h>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <cstdlib>
#define div1 1000000007
const long long INF = 1LL << 60;
using namespace std;
using ll = long long;
// a>b -> a==b;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// a<b -> a==b;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

template <class T> void swap(T& a, T& b) { T t = std::move(a); a = std::move(b); b = std::move(t); }

int main(void)
{
    ll H, W, N, i, j, a[100001], count, count2, ch=0, h, w, color[101][101], d=-1;
    
    cin >> H >> W >> N;

    for(i=1; i<=N; i++){
        cin >> a[i];
    }

    count = 1;
    h = 1; w = 1;
    
    while(1){
        color[h][w] = count;
        ch++;

        count2++;

        if(count2 >= a[count]){
            count2 = 0;
            count++;
        }

        if(ch==H*W){
            break;
        }
        else if(d==-1 && h<H){
            h++;
        }
        else if(d==-1){
            d = 1;
            w++;
        }
        else if(d==1 && h>1){
            h--;
        }
        else if(d==1){
            d = -1;
            w++;
        }
    }

    for(i=1; i<=H; i++){
        for(j=1; j<=W; j++){
            cout << color[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}