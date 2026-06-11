#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < (n); ++i)
typedef long long ll;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    ll A;
    map<int,int> a;
    int c1=0,c2=0,c4=0;
    while(N--) {
        cin >> A;
        if(A%4==0) ++c4;
        else if(A%2==0) ++c2;
        else ++c1;
    }
    if(c2 == 0) {
        if(c1 - 1 <= c4) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else {
        if(c1 <= c4) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    
}
