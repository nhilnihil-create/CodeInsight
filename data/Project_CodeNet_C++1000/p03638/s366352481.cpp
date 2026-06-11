#include <iostream>
#include <algorithm>
#include <math.h>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
using namespace std;
using ll = long long;
using graph = std::vector<std::vector<long long>>;
int main(){
    ll H,W,N;
    cin >> H >> W >> N;
    queue<ll> c;
    for(int i =0 ; i< N; i++){
        ll tmp;
        cin >> tmp;
        for(int j =0; j < tmp; j++){
            c.push(i+1);
        }
    }
    ll m[H][W];
    for(int yi = 0; yi < H; yi++){
        for(int xi = 0; xi < W; xi++){
            if(yi % 2 == 0){
                m[yi][xi] = c.front();c.pop();
            }else{
                m[yi][W - 1 - xi] = c.front();c.pop();
            }
        }
    }

    for(int yi = 0; yi < H; yi++){
        for(int xi = 0; xi < W; xi++){
            cout << m[yi][xi] << " ";
        }
        cout << endl;
    }

}