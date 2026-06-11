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
    string S, T;
    ll Q;
    ll a, b, c, d;
    cin >> S >> T;
    cin >> Q;
    ll L, M;
    L = S.length();
    M = T.length();
    vector<ll> U(L+1), V(M+1);
    U[0] = 0;
    V[0] = 0;

    for (int i = 1; i < L+1; i++) {
        if(S[i-1] == 'A'){
            U[i] = U[i-1] + 1;
        }
        else{
            U[i] = U[i-1] + 2;
        }        
    }
    for (int i = 1; i < M+1; i++) {
        if(T[i-1] == 'A'){
            V[i] = V[i-1] + 1;
        }
        else{
            V[i] = V[i-1] + 2;
        }        
    }

    for (int i = 0; i < Q; i++) {
        cin >> a >> b >> c >> d;
        if((U[b] - U[a-1])%3 == (V[d] - V[c-1])%3){
            YES();
        }
        else{
            NO();
        }
    }


}   