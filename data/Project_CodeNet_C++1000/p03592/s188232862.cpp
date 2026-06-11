#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    int n,m,k;
    cin >> n >> m >> k;
    rep(i, 0, n+1){
        rep(j, 0, m+1){
             if(k == i*m+j*n-i*j*2){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}

