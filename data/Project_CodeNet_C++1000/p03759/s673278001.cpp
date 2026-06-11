#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;
#include <cstdio>
#include <tuple>
#include <string>
#include <vector> 
#include <set>
#include <string.h>
#include <map>
#include <cmath>
using Graph = vector<vector<int>>;
using Graph_Wei = vector<vector<pair<int,int>>>;
using ll = long long;
const long long INF = 1LL<<60; // 仮想的な無限大の値
vector<bool> seen;

Graph G;


int a[4];
int main() {
    
    int a1,a2,a3;
    cin >> a1 >> a2 >> a3;
    if(a2 - a1 == a3 - a2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;

}
