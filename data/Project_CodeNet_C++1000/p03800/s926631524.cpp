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
    int N;
    string S, tmp;
    int t;
    cin >> N >> S;
    for (int i = 0; i < 4; i++) {
        if(i % 2 == 0){
            tmp = 'S';
        }
        else{
            tmp = 'W';
        }
        if((i/2) % 2 == 0){
            tmp += 'S';
        }
        else{
            tmp += 'W';
        }

        for (int j = 2; j < N; j++) {
            t = 0;
            if(tmp[j-2] == 'W') t++;
            if(tmp[j-1] == 'W') t++;
            if(S[j-1] == 'x') t++;
            if(t % 2 == 1){
                tmp += 'W';
            }
            else{
                tmp += 'S';
            }
        }
        t = 0;
        if(tmp[N-2] == 'W') t++;
        if(tmp[N-1] == 'W') t++;
        if(tmp[0] == 'W') t++;
        if(S[N-1] == 'x') t++;
        if(t % 2 == 0){
            t = 0;
            if(tmp[N-1] == 'W') t++;
            if(tmp[0] == 'W') t++;
            if(tmp[1] == 'W') t++;
            if(S[0] == 'x') t++;
            if(t % 2 == 0){
                printf("%s\n", tmp.c_str());
                return 0;
            }
        }

    }
    printf("-1\n");

}