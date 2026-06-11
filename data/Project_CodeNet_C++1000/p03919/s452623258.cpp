#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define PI 3.1415926535897932384626433
#define mod 1000000007

int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main(){
    int h, w;
    cin >> h >> w;
    string s[h][w];
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            cin >> s[i][j];
        }
    }
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if(s[i][j] == "snuke"){
                printf("%c%d\n", 'A' + j , i+1);
            }
        }
    }
    return 0;
}
