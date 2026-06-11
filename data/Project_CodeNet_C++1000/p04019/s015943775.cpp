#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    string S;
    cin >> S;
    int n = 0, w = 0, s = 0, e = 0;
    int len = (int)S.size();
    rep(i, len){
        switch(S.at(i)){
            case 'N':
            n = 1;
            break;
            case 'W':
            w = 1;
            break;
            case 'S':
            s = 1;
            break;
            case 'E':
            e = 1;
            break;
        }
    }
    if((n + s != 1) && (w + e != 1)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}