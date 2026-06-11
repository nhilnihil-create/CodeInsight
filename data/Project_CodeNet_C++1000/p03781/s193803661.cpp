#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int x;
    cin >> x;
    int sum = 0;
    int t;
    for(t=1;; t++){
        sum+=t;
        if(sum >= x) break;
    }
    cout << t << endl;
    return 0;
}