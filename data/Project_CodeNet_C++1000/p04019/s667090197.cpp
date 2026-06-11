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
//typedef long long ll;
//typedef long double ld;
//typedef unsigned long long ull;
//typedef unsigned long double uld;
typedef pair<int,int> P;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
template<class T> inline bool chmax(T &a,T& b){if(a < b){a = b; return true;} else return false;}
template<class T> inline bool chmin(T &a,T& b){if(a > b){a = b; return true;} else return false;}
//struct area

//function area

//main area
int main(){
    char check[4] = {'N', 'W', 'S', 'E'};
    string s;
    cin >> s;
    int n = s.size();
    vector<bool> count_NWSE(4, false);
    rep(i, n){
        rep(j, 4){
            if(s[i] == check[j]){
                count_NWSE[j] = true;
            }
        }
    }
    if(count_NWSE[0] ^ count_NWSE[2] || count_NWSE[1] ^ count_NWSE[3]){
        cout << "No" << endl;
    }
    else{
        cout << "Yes" << endl;
    }
}
/*

N y += any
W x -= any
S y -= any
E x += any

*/