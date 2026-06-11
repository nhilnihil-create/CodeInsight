#include <stdio.h>
#include <iostream>

using namespace std;

    int main(){
    int n;
    cin >> n;
    int problems[n+5];
    int sum = 0;

    for (int i=1; i<=n; i++){
        cin >> problems[i];
        sum += problems[i];
    }

    int m;
    cin >> m;
    int drinks[m+5];
    int times[m+5];

    for (int i=1; i<=m; i++){
        cin >> drinks[i] >> times[i];
    }

    for (int i=1; i<=m; i++){
        int ans = sum;
        ans -= problems[drinks[i]];
        ans += times[i];
        printf("%d\n", ans);
    }

}
