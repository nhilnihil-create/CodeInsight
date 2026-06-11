#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 1; i < (int)(n+1); i++)
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c,a1,b1,c1,cnt = 0;
    cin >> a >> b >> c;
    if(a == b && c == b && a%2 == 0){
        cout << "-1" << endl;exit(0);
    }
    while(a%2 == 0 && b%2 == 0 && c%2 == 0){
        a1 = b/2 + c/2;
        b1 = a/2 + c/2;
        c1 = a/2 + b/2;
        a = a1;b = b1;c = c1;
        //cout << a<<b<<c <<"\n";
        cnt++;
    }
    cout << cnt << endl;
}