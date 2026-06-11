#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<utility>
#include<string>
#include<map>
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
    int n, p;
    cin >> n >> p;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    bool flag = true;
    for(int i = 0; i < n; i++){
        if(a[i]%2 == 1) flag = false;
    }

    if(flag == true){
        if(p == 0){
            ans = pow(2, n);
        }
        else{
            ans = 0;
        }
    }
    else{ 
        ans = pow(2, n-1);
    }

    cout << ans << endl;
    return 0;
}
