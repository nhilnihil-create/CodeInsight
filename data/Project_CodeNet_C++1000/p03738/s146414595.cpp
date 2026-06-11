#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uld = unsigned long long;
using P = pair<int,int>;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
template<class T> inline bool chmax(T &a,T& b){if(a < b){a = b; return true;} else return false;}
template<class T> inline bool chmin(T &a,T& b){if(a > b){a = b; return true;} else return false;}
//struct area

//function area

//main area
int main(){
    string a, b;
    cin >> a >> b;
    bool check = true;
    if(a.size() == b.size()){
        rep(i,a.size()){
            if(a[i] == b[i]) continue;
            else{
                check = false;
                cout << (a[i] > b[i] ? "GREATER" : "LESS") << endl;
                break;
            }
        }
    }
    else{
        check = false;
        cout << (a.size() > b.size() ? "GREATER" : "LESS") << endl;
    }
    if(check) cout << "EQUAL" << endl;
}
/*

1 size比較
2 同じなら、位の大きい桁から比較
3 全て同じならEQUAL Aが大きいならGREATER

*/