//070 A - Palindromic Number 2017/08/12
#include <bits/stdc++.h>
#define rep(i ,n) for(int i=0;i<(int)(n);++i)
using namespace std;
typedef long long int int64;
typedef unsigned long long uint64;

int main(){
    int n; cin >> n;
    cout << ((n%10==((n/10)/10)%10) ? "Yes" : "No" ) << endl; 
}