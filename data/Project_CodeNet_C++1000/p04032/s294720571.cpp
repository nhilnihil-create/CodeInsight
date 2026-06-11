#include <iostream>
#include <algorithm>
#include <limits>
#include <vector>
#include <map>
#include <cmath>
#include <limits>
#include <iomanip>
#include <queue>
#include <bitset>
#define ll long long int
#define ld long double
#define rep(i,n) for(int i = 0;i < n;i++)
#define rep1(i,n) for(int i = 1;i < n;i++)
#define co(x) cout << x << endl
#define cosp(x) cout << x << " "
#define all(x) x.begin(),x.end()
#define p pair<ll,ll>
#define pb push_back
#define mp make_pair
#define MOD 1000'000'007
#define INF 1ll << 60
#define PI 3.14159265359

using namespace std;
int main(){
    string s;
    cin >> s;
    for(int i = 0;i < s.size();i++){
        if(i){
            if(s[i] == s[i-1]){
                cout << i << " " << i+1 << endl;
                return 0;
            }
            if(i > 1){
                if(s[i-2] == s[i]){
                    cout << i - 1 << " " << i+1 << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}