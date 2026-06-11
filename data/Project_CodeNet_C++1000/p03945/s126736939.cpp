/**
*    author:  souzai32
*    created: 04.08.2020 01:37:27
**/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {

    string s;
    cin >> s;
    int n=s.size();
    int count=0;

    rep(i,n-1) if(s.at(i+1)!=s.at(i)) count++;

    cout << count << endl;

    return 0;
}