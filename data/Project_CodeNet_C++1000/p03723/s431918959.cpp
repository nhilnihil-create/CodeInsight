#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <vector>
#include <cstring>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
ll MAX(ll a,ll b,ll c){return max(a,max(b,c));}
ll MIN(ll a,ll b,ll c){return min(a,min(b,c));}
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
template<class T> inline bool chmax(T &a,T& b){if(a < b){a = b; return true;} else return false;}
template<class T> inline bool chmin(T &a,T& b){if(a > b){a = b; return true;} else return false;}
int main(){
    ll a,b,c;
    cin >> a >> b >> c;
    ll counter = 0;
    if(a==b && b==c){
        if(a%2==1) counter = 0;
        else counter = -1;
    }
    else{
        while(true){
            if(a%2==0 && b%2==0 && c%2==0){
                ll na,nb,nc;
                na = ( b + c ) / 2; nb = ( a + c ) / 2; nc = ( a + b ) / 2;
                a = na; b = nb; c = nc;
                counter++;
            }
            else break;
        }
    }
    cout << counter << endl;
}