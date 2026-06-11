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
    cin >> n;
    int a=n/10;
    int b = n - a*10;
    if (a==9 || b==9){
        std::cout << "Yes";
        return 0;
    }
    std::cout << "No";

    return 0;
}