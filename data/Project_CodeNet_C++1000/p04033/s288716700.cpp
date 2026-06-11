#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    ll a,b;
    cin >> a >> b;
    if(a > 0){
        cout << "Positive" <<endl;
    }
    else if(a == 0){
        cout << "Zero" <<endl;
    }
    else{
        if(b >= 0){
            cout << "Zero" <<endl;
        }
        else{
            if((b-a) % 2 == 0){
                cout << "Negative" <<endl;
            }
            else{
                cout << "Positive" <<endl;
            }
        }
    }


}   