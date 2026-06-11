/*
      author : nishi5451
      created: 11.08.2020 00:41:10
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

int group(int n){
    switch (n){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return 1;
        case 4:
        case 6:
        case 9:
        case 11: return 2;
        case 2: return 3;
    }
}

int main(){
    int x,y;
    cin >> x >> y;
    if(group(x) == group(y)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}