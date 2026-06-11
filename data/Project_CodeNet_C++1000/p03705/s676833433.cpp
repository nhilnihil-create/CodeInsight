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

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}
int lcm(int a, int b){return a*b / gcd(a, b);}



int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    if(n == 1){
        if(a != b) cout << 0 << endl;
        else cout << 1 << endl;
    }
    else{
        if(a > b) cout << 0 << endl;
        else cout << (n-2)*(b-a)+1 << endl;
    }
    return 0;
}
