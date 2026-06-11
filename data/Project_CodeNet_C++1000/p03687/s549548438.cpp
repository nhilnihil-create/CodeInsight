#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    string s;
    cin >> s;
    vector<bool> c(26);
    vector<bool> tmp(26);
    int n = s.length();
    for (int l = 1; l < n+1; l++) {
        fill(ALL(c), true);
        for (int i = 0; i < n-l+1; i++) {
            fill(ALL(tmp), false);
            for (int j = 0; j < l; j++) {
                tmp[s[i+j] - 'a'] = true;        
            }
            for (int j = 0; j < 26; j++) {
                if(!tmp[j]) c[j] = false;
            }
        }   

        for (int i = 0; i < 26; i++) {
            if(c[i]){
                printf("%d\n", l-1);
                return 0;
            }
        }

    }

}