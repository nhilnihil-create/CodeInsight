#include <bits/stdc++.h>
#define PI 3.1415926535897
using namespace std;
typedef long long ll;
const int INF = 1000000000;
const ll LINF = 1000000000000000000; //1e18
const double EPS = 1e-10;            //

int main(void)
{
    string s;
    cin >> s;

    printf("%c", s[0]);
    int cnt = s.size() - 2;
    printf("%d", cnt);
    printf("%c\n", s[s.size() - 1]);
    return (0);
}