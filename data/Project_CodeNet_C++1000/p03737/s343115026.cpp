#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include<cctype>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for (int i = s; i < (int)(n); i++)
#define out(x) cout << x << endl
#define INF 1000000;
#include <map>
#include <math.h>
 
using ll = long long;
using namespace std;

ll n, k;
const ll mod = 1000000007;

int main(){
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    string ans;
    ans.push_back(s1[0]);
    ans.push_back(s2[0]);
    ans.push_back(s3[0]);
    transform(ans.begin(), ans.end(), ans.begin(), ::toupper);
    cout << ans << endl;
    // cout << (char)(s1[0]-0x20) << (char)(s2[0]-0x20) << (char)(s3[0]-0x20) << endl;
}
