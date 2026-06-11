#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define MIN(a,b) ((a)>(b)? (b): (a))
#define MAX(a,b) ((a)<(b)? (b): (a))

const long long INF = 1LL << 60;
typedef unsigned long long ll;
const long long MOD = 1000000000 + 7;

int main(){
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    char i1,i2,i3;
    i1 = toupper(s1[0]);
    i2 = toupper(s2[0]);
    i3 = toupper(s3[0]);
    cout << i1 << i2 << i3 << endl;
    return 0;
}