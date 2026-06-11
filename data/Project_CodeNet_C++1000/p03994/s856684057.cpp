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
    int K;
    cin >> K;

    int ind = 0;
    int N = s.length();
    while(K > 0){
        if(ind == N-1){
            int p = s[N-1] - 'a';
            p += K;
            p = p % 26;
            s[N-1] = 'a' + p;
            K = 0;
        }
        else{
            if(s[ind] != 'a'){
                if(26 - (s[ind] - 'a') <= K){
                    K -= (26 - (s[ind] - 'a'));
                    s[ind] = 'a';
                    ind++;
                }
                else{
                    ind++;
                }
            }
            else{
                ind++;
            }
        }

    }

    printf("%s\n", s.c_str());

}