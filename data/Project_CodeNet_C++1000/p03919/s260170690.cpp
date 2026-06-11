#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cmath>
#include <map>
#include <set>
#define ull unsigned long long
#define ll long long
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    string s[h][w];
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            cin >> s[i][j];
        }
    }
    char q='A';
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=="snuke"){
                cout << q << i+1 << endl;
                return 0;
            }
            q++;
        }
        q='A';
    }
    return 0;
}