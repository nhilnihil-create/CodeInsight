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
    int N, x;
    cin >> N >> x;
    if(x == 1 || x == 2 * N - 1){
        No();
        return 0;
    }
    if(x == 2){
        Yes();
        for (int i = 3; i < N+1; i++) {
            printf("%d\n", i);
        }
        printf("%d\n", 1);
        printf("%d\n", 2);
        for (int i = N+1; i < 2*N; i++) {
            printf("%d\n", i);  
        }
    }
    else{
        queue<int> q;
        for (int i = 1; i < x-2; i++) {
            q.push(i);
        }
        for (int i = x+2; i < 2*N; i++) {
            q.push(i);
        }
        Yes();
        int tmp;
        for (int i = 0; i < N-3; i++) {
            tmp = q.front();
            q.pop();
            printf("%d\n", tmp);
        }
        printf("%d\n", x-2);
        printf("%d\n", x+1);
        printf("%d\n", x);
        printf("%d\n", x-1);
        while(!q.empty()){
            tmp = q.front();
            q.pop();
            printf("%d\n", tmp);    
        }
    }


}