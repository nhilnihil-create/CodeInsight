#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if(a==b && a==c){
        cout << 1 << endl;
    }
    else if(a==b){
        cout << 2 << endl;
    }
    else if(b==c){
        cout << 2 << endl;
    }
    else if(c==a){
        cout << 2 << endl;
    }
    else{
        cout << 3 << endl;
    }
    return 0;
}
