#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a == 1 && b == 1 && c == 1){
        cout << 0 << endl;
        return 0;
    }
    if(a == b && b == c && c == a){
        cout << -1 << endl;
        return 0;
    }
    int count = 0;
    while(a%2 == 0 && b%2 == 0 && c%2== 0){
        count++;
        int p,q,r;
        p = a/2;
        q = b/2;
        r = c/2;
        a = q+r;
        b = r+p;
        c = p+q;
    }
    cout << count << endl;
    
    return 0;
}
