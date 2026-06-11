#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()
    
int main(){
    long long a,b,x;
    cin >> a >> b>> x;
    if(a==0 && b==0) cout << 1 << endl;
    else if(a==0){
        cout << b/x + 1 << endl;
    }
    else{
        cout << b/x - (a-1)/x << endl;
    }
}
