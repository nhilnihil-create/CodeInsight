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
    int a, b;
    cin >> a >> b;
    string ans;

    if(a>0 && b>0) ans = "Positive";
    if(a<=0 && b>=0) ans = "Zero";
    if(a<0 && b<0){
        if((b-a)%2 == 0) ans = "Negative";
        else ans = "Positive";
    }

    cout << ans << endl;
    return 0;
}
