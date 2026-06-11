#include <bits/stdc++.h>
using namespace std;
#define repr(i, a, b) for (int i = a; i < b; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a<=c){
        if(c<=b){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}