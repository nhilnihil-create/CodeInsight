#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define MOD 1000000007
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(v) v.begin(), v.end()
typedef long long ll;

int main(){
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    char dif = 'A' - 'a';
    cout << char(s1[0]+dif) << char(s2[0]+dif) << char(s3[0]+dif) << endl;



    return 0;
}

