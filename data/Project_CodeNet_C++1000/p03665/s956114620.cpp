#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;

//計算量O(k)
// nPk
long long permutation(int n, int k){
    long long perm = 1;
    for(int i = 0; i < k; i++){
        perm *= (n - i);
    }

    return perm;
}

//計算量O(min(k,n-k))
// nCk
long long combination(int n, int k){
    long long cns = min(k,n-k);
    long long com = permutation(n,cns);
    for(int i = 0; i < cns; i++){
        com /= (cns - i);
    }

    return com;
} 


int main(){
    int n,p;
    cin >> n >> p;

    int num0 = 0;
    int num1 = 0;

    rep(i,n){
        int a;
        cin >> a;
        if(a % 2 == 0) num0 ++;
        else num1 ++;
    }

    long long ans = 0;

    if(p == 0){
        for(int i = 0; i<=num1; i+=2){
            ans += combination(num1,i) * pow(2,num0);
        }
        cout << ans << endl;
        return 0;
    }

    if(p == 1){
        for(int i=1; i<=num1; i+=2){
            ans += combination(num1,i) * pow(2,num0);
        }
        cout << ans << endl;
        return 0;
    }

}