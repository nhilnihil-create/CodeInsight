#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a%2==0&&a==b&&b==c){
        cout << -1 << endl;
        return 0;
    }
 
    if(a%2!=0||b%2!=0||c%2!=0){
        cout << 0 << endl;
        return 0;
    }
    
    int ans = 0;
 
    while(true){
        int aa = a,bb= b,cc=c;
        a = bb/2 + cc/2;
        b = aa/2 + cc/2;
        c = aa/2 + bb/2;
        ans++;
        if(a%2!=0||b%2!=0||c%2!=0){
            break;
        }
    }
 
 
    cout << ans << endl;
}
