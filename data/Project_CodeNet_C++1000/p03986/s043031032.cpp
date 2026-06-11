#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
 
using namespace std;

int main(){
    string X;   cin >> X;
    int l = X.length();
    int cs, ct, ans;
    ans = l;
    for(int i=0; i<l; i++){
        if(X[i] == 'T'){
            if(cs > 0){
                cs--;
                ans -= 2;
            }
        }else   cs++;
    }
    print(ans);
    return 0;
}