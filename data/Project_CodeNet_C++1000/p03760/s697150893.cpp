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
    string odd, even;
    cin >> odd >> even;
    if(odd.size()==even.size()){
        rep(i, odd.size()){
            cout << odd[i] << even[i];
        }
    }
    else{
        rep(i, even.size()){
            cout << odd[i] << even[i];
        }
        cout << odd[odd.size()-1];
    }
    cout << endl;
}
/*

cout << odd[0] << even[0] << odd[1] << even[1] << ... << odd[n-1]

*/