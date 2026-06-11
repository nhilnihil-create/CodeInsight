#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    string S;
    cin >> S;

    ll n = S.size();
    n--;
    while(true){
        if(n % 2 == 1){
            n--;
            continue; 
        }
        if(S.substr(0, n/2) == S.substr(n/2, n/2)){
            cout << n << endl;
            break;
        }
        n--;
    }
    return 0;
}
