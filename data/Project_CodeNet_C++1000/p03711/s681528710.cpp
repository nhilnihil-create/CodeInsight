#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int x, y;
    cin >> x >> y;
    set<int> a = {4,6,9,11};

    if(x == 2 || y == 2){
        if(x == y) puts("Yes");
        else puts("No");
    }
    else if(a.count(x) || a.count(y)){
        if(a.count(x) == a.count(y)) puts("Yes");
        else puts("No");
    }
    else puts("Yes");
}