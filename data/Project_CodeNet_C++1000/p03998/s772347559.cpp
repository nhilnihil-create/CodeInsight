#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll one = 1;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    string a,b,c;
    int ia, ib, ic;
    cin >> a >> b >> c;
    ia = 0; ib = 0; ic = 0;
    int na = a.length();
    int nb = b.length();
    int nc = c.length();
    int tmp = 1;
    while(true){
        if(tmp == 1){
            if(ia == na){
                printf("A\n");
                return 0;
            }
            tmp = a[ia] - 'a' + 1;
            ia++;
        }
        else if(tmp == 2){
            if(ib == nb){
                printf("B\n");
                return 0;
            }
            tmp = b[ib] - 'a' + 1;
            ib++;
        }
        else{
            if(ic == nc){
                printf("C\n");
                return 0;
            }
            tmp = c[ic] - 'a' + 1;
            ic++;
        }
    }

}