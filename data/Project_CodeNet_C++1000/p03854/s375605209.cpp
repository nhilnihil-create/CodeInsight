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

int main(){
    string S;
    cin >> S;
    int N = S.length();

    int right = N-1;
    while(right >= 0){
        if(right >= 5 && S.substr(right - 5, 6) == "eraser"){
            right -= 6;
        }
        else if(right >= 4 && S.substr(right - 4, 5) == "erase"){
            right -= 5;
        }
        else if(right >= 6 && S.substr(right - 6, 7) == "dreamer"){
            right -= 7;
        }
        else if(right >= 4 && S.substr(right - 4, 5) == "dream"){
            right -= 5;
        }
        else {
            printf("NO\n");
            return 0;
        }


    }

    printf("YES\n");
}