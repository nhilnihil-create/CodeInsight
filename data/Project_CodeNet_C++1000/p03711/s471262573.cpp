#include <bits/stdc++.h>
using namespace std;

int main() {
    int x,y;
    int a[] ={0,2,0,1,0,1,0,0,1,0,1,0};
    cin >> x >> y;
    if (a[x-1]==a[y-1]){
        printf("Yes");
    }else{
        printf("No");
    }

    return 0;
}