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
    string s;
    cin >> s;
    int first, last;
    rep(i,s.size()){
        if(s[i] == 'A'){
            first = i;
            break;
        }
    }
    for(int i = s.size()-1; 0<=i; i--){
        if(s[i] == 'Z'){
            last = i;
            break;
        }
    }
    cout << last - first + 1 << endl;
}
/*



*/