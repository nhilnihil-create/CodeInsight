#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    
    rep(i,n+1){
        rep(j,m+1){
            int tmp = i*m+j*n -2*(i*j);
            //cout <<i << " " << j << " " << i*m << "-" << j*n << " "  << tmp << endl;

            if(tmp == k){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}