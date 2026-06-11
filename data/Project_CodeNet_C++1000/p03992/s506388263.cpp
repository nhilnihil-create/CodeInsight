#include <iostream>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <limits>
#include <vector>
#define ll long long
#define rep(i,n) for(int i = 0;i < n;i++)
#define pb push_back
#define mp make_pair

using namespace std;

int main(){
    string s;
    cin >> s;
    rep(i,4){
        cout << s[i];
    }
    cout << " ";
    for(int i = 4;i < 12;i++){
        cout << s[i];
    }
    cout << endl;
    return 0;
}