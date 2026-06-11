#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    long n,a,b;
    cin >> n >> a >> b;
    if(n<2){
        if(a==b) cout << 1 << endl;
        else cout << 0 << endl;
    }
    else{
        if(a<=b) cout <<(b-a)*(n-2)+1 << endl;
        else cout << 0 << endl;
    }
}
