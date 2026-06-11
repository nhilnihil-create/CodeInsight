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
    string X;
    cin >> X;
    ll N = X.length();
    
    stack<char> S;
    
    for (int i = 0; i < N; i++) {
        if(S.empty()){
            S.push(X[i]);
        }    
        else if(S.top() == 'S' && X[i] == 'T'){
            S.pop();
        }
        else{
            S.push(X[i]);
        }
    }
    int ans = S.size();
    printf("%d\n", ans);

}