#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b){if(a < b){ a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b){if(a > b){ a = b; return 1;} return 0;}

const int INF = 100000; 

int main(){
    int a, b;
    cin >> a >> b;

    if(a % 3 == 0 || b % 3 == 0 || (a+b) % 3 == 0){
        cout << "Possible" << endl;
    }else{
        cout << "Impossible" << endl;
    }
    
    return 0;
}
