#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
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
    int H, W;
    cin >> H >> W;
    string s;
    vector<int> c(26, 0);
    for (int i = 0; i < H; i++) {
        cin >> s;
        for (int j = 0; j < W; j++) {
            c[s[j] - 'a']++;
        }
    }

    int odd, two;
    odd = 0; two = 0;
    for (int i = 0; i < 26; i++) {
        if(c[i] % 2 == 1){
            odd++;
        }
        if(c[i] % 4 == 2 || c[i] % 4 == 3){
            two++;
        }
    }

    bool ans = false;
    if(H%2 == 0 && W%2 == 0){
        if(odd == 0 && two == 0){
            ans = true;
        }
    }
    else if(H%2 == 1 && W%2 == 1){
        if(odd <= 1 && two <= (H+W-2)/2){
            ans = true;
        }
    }
    else if(H%2 == 1){
        if(odd == 0 && two <= W/2){
            ans = true;
        }
    }
    else{
        if(odd == 0 && two <= H/2){
            ans = true;
        }
    }

    if(ans){
        Yes();
    }
    else{
        No();
    }

}