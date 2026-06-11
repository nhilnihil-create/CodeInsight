#include <bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
#define rep(X,N) for(ll X = 0; X < (N); X++)
#define PI (acos(-1.0))
#define pback push_back
#define mpair make_pair
#define MODN 1000000007
#define ALL(V) (V).begin(),(V).end()
#define CERR if(false) cerr

typedef long long ll;

using namespace std;
//using namespace boost::multiprecision;

int main(){

    string s;
    cin >> s;

    //貪欲に前からパーが出せるときにはパーを出す

    int n = s.size();
    int ans = 0;
    int paperable = 1;

    if(s[0] == 'p'){
        ans--;
    }

    for(int i = 1; i < n; i++){
        if(paperable > 0){
            paperable--;
            if(s[i] == 'g'){
                ans++;
            }
        }else{
            paperable++;
            if(s[i] == 'p'){
                ans--;
            }
        }
    }

    cout << ans << endl;

    
    return 0;
}