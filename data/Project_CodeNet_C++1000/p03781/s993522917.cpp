#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;
typedef long long lng;
#define UP(i,a,b) for(int i=(a); i<=(b); ++i)
#define DOWN(i,b,a) for(int i=(b); i>=(a); --i)
#define REP(i,n) UP(i,0,n-1)
#define ALL(a) (a).begin(), (a).end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end()) //NOTE: <a> must be sorted in advance

lng power(lng b, int n) {lng sol=1; while(n>0) {if(n&1) {sol=sol*b;} n>>=1; b*= b;} return sol;} //calculate b^n

const int MOD = 1000000007; //10^9+7
const double PI = 3.1415926535897932384626;

/*********** variables ************/
int X;
/**********************************/


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> X;

    int x = 0;
    for(int i=0; ; i++) {
        if(x >= X) {
            cout << i << endl;
            return 0;
        }
        x += i+1;
    }
}
