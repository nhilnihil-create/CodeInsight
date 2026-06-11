#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i< (n); ++i)
#define vvec(m,n) vector<vector<int>> (int(m), vector<int>(n))
#define ALL(a) (a).begin(), (a).end()

using ll = long long;

int main(){
    char a, b;
    cin >> a >> b;
    if(a == 'H'){
        if(b == 'H'){
            cout << 'H' << endl;
        }else{
            cout << 'D' << endl;
        }
    }else{
        if(b == 'H'){
            cout << 'D' << endl;
        }else{
            cout << 'H' << endl;
        }
    }
}