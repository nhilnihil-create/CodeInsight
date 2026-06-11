#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    int N;
    cin >> N;
    int odd = 0;
    int even = 0;
    rep(i,N){
        int A;
        cin >> A;
        if (A % 2 == 0) even++;
        else odd++;
    }
    if (odd % 2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}

