#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include<string>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int gcd(int a, int b){return b ? gcd(b, a%b) : a;}

int main(){
    int a, b ,c;
    cin >> a >> b >> c;

    int cnt = 0;
    for(int i = 0; i < 100; i++){
        if(a%2!=0 || b%2!=0 || c%2!=0){
            cout << cnt << endl;
            return 0;
        }

        int a_even = a/2, b_even = b/2, c_even = c/2;
        a = b_even+c_even;
        b = c_even+a_even;
        c = a_even+b_even;
        cnt++;
    }
    cout << -1 << endl;
    return 0;
}
