#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    transform(s2.begin(), s2.end(), s2.begin(), ::toupper);
    transform(s3.begin(), s3.end(), s3.begin(), ::toupper);
    cout << s1.at(0) << s2.at(0) << s3.at(0) << endl;
}