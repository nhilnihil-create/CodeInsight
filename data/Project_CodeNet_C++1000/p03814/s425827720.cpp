#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <cctype>
#include <map>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>


#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")

#define rep(i, n) for (int i = 0; i < (int)(n); i++)



using namespace std;

bool is_integer( float x ){
    return floor(x)==x;
}


int main() {

    string s;
    int maxPoint = 0;
    int minPoint = 0;

    cin >> s;
    int n = s.length();

    rep(i,n){
        if(s[i] == 'A'){
            minPoint = i;
            break;
        }
    }
    rep(i,n){
        if(s[n-1-i] == 'Z'){
            maxPoint = n-1-i;
            break;
        }
    }
    cout << maxPoint - minPoint + 1;

    return 0;
}









