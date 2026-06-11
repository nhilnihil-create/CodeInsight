#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    int a,b;
    cin >> a >> b;
    if(a==1){
        if(b==1) cout << "Draw" << endl;
        else cout << "Alice" << endl;
    }else if(b==1){
        cout << "Bob" << endl;
    }else{
        if(a>b) cout << "Alice" << endl;
        else if(a==b) cout << "Draw" << endl;
        else cout << "Bob" << endl;
    }
    return 0;
}