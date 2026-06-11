#include <cstdio>
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
    string n;

    cin >> n;
    int l=n.length();

    // cout << l/2 << n << n[l-1] << endl;

    for (int i=1;i<=(l/2);i++) {
        if (n[i-1]==n[l-i]){
            // cout << "fs";
        }
        else {
            cout << "No";
            break;
        }
        cout << "Yes" ; 
    }


    return 0;
}