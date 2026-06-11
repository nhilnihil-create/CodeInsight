#include <bits/stdc++.h>

using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;

bool dp[100100];

int main () {
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;

    cout <<(char) toupper(s1[0]) <<(char)toupper(s2[0])<<(char) toupper(s3[0])<< endl;


    
}

