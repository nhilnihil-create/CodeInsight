#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define PI (acos(-1.0))
#define MODN 1000000007
#define MODN2 998244353
#define ALL(V) (V).begin(),(V).end()
#define INT_MAX_HALF (INT_MAX / 2)
#define EPS (1e-10)

using namespace std;
typedef long long ll;

int main(){

    string s;
    cin >> s;
    int size = s.size();

    vector<bool> exist(26, false);

    rep(i, size){
        exist[(int)(s[i] - 'a')] = true;
    }

    int ans = 26;

    rep(i, 26){
        if(!exist[i]){
            ans = i;
            break;
        }
    }

    if(ans == 26){
        cout << "None" << endl;
    }else{
        cout << (char)('a' + ans) << endl;
    }

    return 0;
}
