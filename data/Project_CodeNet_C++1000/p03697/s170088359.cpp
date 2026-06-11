#include <bits/stdc++.h> 
using namespace std;
#define rep(i, N) for(int i=0; i<N; i++)
typedef long long ll;
#define dump(x) cerr<<#x<<"="<<x<<endl
using P = pair<int, int>;

int main() {
    int a, b; cin >> a >> b;
    if(a+b>=10){
        cout << "error" << endl;
    }
    else cout << a+b << endl;
    return 0;
}
