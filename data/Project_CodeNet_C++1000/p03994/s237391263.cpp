#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    string S;
    int K;
    cin >> S >> K;
    for(int i=0;i<S.size();i++){
        if(S[i]=='a')continue;
        if(S[i]+K>'z'){
            K -= 'z' - S[i] + 1;
            S[i]='a';
        }
    }
    int n = S.size();
    if(K>0){
        K%=26;
        while(K>0){
            if(S[n-1]=='z'){
                S[n-1]='a';
            }else{
                S[n-1] = S[n-1]+1;
            }
            K--;
        }
    }
    cout << S << endl;
    return 0;
}