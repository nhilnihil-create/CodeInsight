#include <bits/stdc++.h>
#include <vector>
#include <queue>
#include <set>
#include <iostream>
#include <iomanip>
using namespace std;
typedef long long LL;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

int main(){
    int n;
    cin >> n;
    vector<LL> a(n);
    REP(i,n)cin>>a[i];

    int count = n - 1;
    while( count >= 0){
        cout << a[count] << " ";
        count -= 2;
    }

    count = (count==-2)? 1:0;
    while(count < n){
        cout << a[count] << " ";
        count+=2;
    }

    return 0;

}