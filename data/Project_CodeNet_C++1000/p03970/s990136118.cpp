#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define PI 3.1415926535897932384626433
#define mod 1000000007

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main(){
    string t = "CODEFESTIVAL2016";
    string s;
    cin >> s;
    int ans = 0;
    for (int i = 0; i < 16; i++){
        if(s[i] != t[i]){
            ans++;
        }
    }
    cout << ans << endl;
}
