#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int res = 1;
    int two = 2;
    while(two<=n){
        res = two;
        two = two*2;
    }
    cout << res << endl;
    return 0;
}