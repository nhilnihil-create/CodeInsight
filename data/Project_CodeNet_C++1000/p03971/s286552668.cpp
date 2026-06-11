#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>

#define ll long long
#define REP(i,n) for(int i = 0; i < (n); ++i)
#define PI 3.141592653589
#define MOD 1000000007

using namespace std;

template<typename T> T gcd(T a, T b){ return (a % b)? gcd(b, a%b) : b; }
template<typename T> T lcm(T a, T b){ return a * b / gcd(a, b); }

int main(void){
    int n, A, B;
    cin >> n >> A >> B;
    string s;
    cin >> s;

    int a = 0, b = 0;
    REP(i,n){
        if(s[i] == 'a'){
            if(a+b < A+B){
                cout << "Yes" << endl;
                a++;
            } else cout << "No" << endl;
        } else if(s[i] == 'b'){
            if(a+b < A+B && b < B){
                cout << "Yes" << endl;
                b++;
            } else cout << "No" << endl;
        } else cout << "No" << endl;
    }
    
    return 0;
}