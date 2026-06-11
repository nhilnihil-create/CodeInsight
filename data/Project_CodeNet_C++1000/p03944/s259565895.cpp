#include <bits/stdc++.h>

#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 1e10
#define ALL(v) v.begin(), v.end()

using namespace std;
typedef unsigned long long ll;

int main(){
    int n, w, h;
    cin >> w>> h >>n;
    int x, y, a;

    pair<int, int> bottom = {0, 0};
    pair<int, int> top = {w, h};

    bool gone = false;

    REP(i, n){
        cin >> x>> y >> a;
        if (a==1){
            if (bottom.first < x) bottom.first = x;
        }
        else if (a == 2){
            if (top.first > x) top.first = x;
        }
        else if (a == 3){
            if (bottom.second < y) bottom.second= y;
        }
        else{
            if (top.second > y) top.second = y;
        }
    }
    if(top.first - bottom.first< 0 || top.second - bottom.second < 0)cout << 0;
    else cout << (top.first - bottom.first)*(top.second - bottom.second )<<endl;
    
    return 0;
}   
        
