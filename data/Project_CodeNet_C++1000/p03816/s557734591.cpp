#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()

typedef long long ll;

using namespace std;
//using namespace boost::multiprecision;

int main(){

    int n;
    cin >> n;

    vector<int> count(100001);

    rep(i,n){
        int tmp;
        cin >> tmp;

        count[tmp]++;
    }

    int one = 0;
    int modzero = 0;
    int modone = 0;

    rep(i, 100001){
        if(count[i] == 1){
            one++;
        }else if(count[i] != 0){
            if(count[i] % 2 == 0){
                modzero++;
            }else{
                modone++;
            }
        }
    }

    int ans = one + modzero + modone;

    if(modzero % 2 == 1){
        ans--;
    }

    cout << ans << endl;

    return 0;
}