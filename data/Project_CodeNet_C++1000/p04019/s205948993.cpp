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
    vector<bool> c(4,false);
    for (char i : S) {
        if(i == 'N'){
            c[0]=true;
        }else if(i == 'S'){
            c[1]=true;
        }else if(i == 'E'){
            c[2]=true;
        }else if(i == 'W'){
            c[3]=true;
        }
    }

    if(c[0] ^ c[1]){
        printf("No\n");
    }else if(c[2] ^ c[3]){
        printf("No\n");
    }
    else{
        printf("Yes\n");
    }

}
