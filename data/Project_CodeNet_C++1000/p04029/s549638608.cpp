#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
//const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int A(int x){
    if (x == 1) return 1;
    else return  x + A(x - 1);
}
int main(){
    int N;
    cin >> N;
    cout << A(N) << endl;
}
