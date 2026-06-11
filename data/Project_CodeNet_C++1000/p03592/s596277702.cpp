#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define repf(i,a,n) for(int i = (int)(a); i < (int)(n); i++)

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
using namespace std;

int main(){
    int n,m,k;
    string ans = "No";
    cin >> n >> m >> k;
    int nm = n*m;
    rep(i,n){
        rep(j,m){
            int t = (i+1)*(j+1)+(n-i-1)*(m-j-1);
            if(t == k || nm - t == k){
                ans = "Yes";
            }
        }
    }
    cout << ans << endl;
}