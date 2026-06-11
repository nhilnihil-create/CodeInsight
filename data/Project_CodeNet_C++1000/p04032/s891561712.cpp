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
//using namespace boost::multiprec

int main(){

    string s;
    cin >> s;

    int a = 0;
    int b = 0;

    if(s[0] == s[1]){
        a = 1;
        b = 2;
    }else{

        for(int i = 2; i < s.size(); i++){
            if(s[i] == s[i - 1]){
                b = i + 1;
                a = i;
                break;
            }else if(s[i] == s[i - 2]){
                b = i + 1;
                a = i - 1;
                break;
            }
        }

    }

    if(a != 0){
        cout << a << " " << b << endl;
    }else{
        cout << -1 << " " << -1 << endl;
    }
    
    return 0;
}