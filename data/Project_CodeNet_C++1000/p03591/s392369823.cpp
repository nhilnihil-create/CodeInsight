#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define PI 3.1415926535897932384626433
#define mod 1000000007

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main(){
    string s;
    cin >> s;
    if(s[0] == 'Y' && s[1] == 'A' && s[2] == 'K' && s[3] == 'I'){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
