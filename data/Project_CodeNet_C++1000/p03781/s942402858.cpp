#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define PI 3.1415926535897932384626433
#define mod 1000000007

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main(){
    int x;
    cin >> x;
    for (int i = 1;; i++){
        x -= i;
        if (x <= 0){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}