#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
using ll = long long;
using namespace std;

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int cnt;
    cin >> n;
    cnt = 0;
    for (int i=0;i<n;i++){
        int a,b;
        cin >> a>>b;
        int c = b-a+1;
        cnt += c;

    }
    cout << cnt;


    return 0;
}