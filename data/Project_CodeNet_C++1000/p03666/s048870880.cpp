#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
using namespace std;
#define rep(i,n) for(int i = 0;i<n;i++)
const long long MOD = 1000000007LL;
const string alpha = "abcdefghijklmnopqrstuvwxyz";
int main(){
    int n;
    cin >> n;
    long long a,b,c,d;
    cin >> a >> b >> c >> d;
    b-=a;
    long long inf,sup;
    for(int i = 0;i<=n-1;i++){
        inf = c*i-(n-1-i)*d;
        sup = d*i-(n-1-i)*c;
        if(inf<=b && b<=sup){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}