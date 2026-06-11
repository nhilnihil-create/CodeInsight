//061 A - Between Two Integers 2017/05/13

#include <bits/stdc++.h>
#define rep(i ,n) for(int i=0;i<(int)(n);++i)
using namespace std;
typedef long long int int64;
typedef unsigned long long uint64;

int main(){
    int a , b , c;
    cin >> a >> b >> c;
    cout  << ( (c >= a && c <= b) ? "Yes" : "No" ) << endl;
}