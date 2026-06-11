#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<vector>
using namespace std;
typedef long long llong;
int main(){
    int n;
    cin >> n;
    
    llong ax, ay;
    int x, y;

    cin >> x >> y;
    ax = x; 
    ay = y;

    for (int i = 0; i < n - 1; i++){
        scanf("%d %d", &x, &y);

        if (ax < x) ax = x;
        else if (ax % x != 0) ax += x - (ax % x);

        if ((ax / x) * y < ay) ax += (ay - (ax / x) * y) / y * x;
        if ((ax / x) * y < ay) ax += x;

        ay = ax / x * y;
    }

    cout << ax + ay << endl;
    return 0;
}