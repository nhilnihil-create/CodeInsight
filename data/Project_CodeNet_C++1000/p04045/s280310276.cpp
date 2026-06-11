#include <bits/stdc++.h>

using namespace std;
int a[15];
int main()
{
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);
    int n;int k;
    cin >> n >> k;
    int temp;
    while(k--){
        cin >> temp;
        a[temp] ++;
    }

    for (int i=n;;++i){
        int temp = i;
        while (temp){
            if (a[temp%10]){
                break;
            }else temp /=10;
        }
        if (temp==0) {
            cout << i;
            break;
        }

    }
    return 0;
}
