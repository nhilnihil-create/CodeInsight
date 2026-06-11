#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, n, temp;
    cin >> k >>n;
    unordered_map<int, int> map;
    for(int i=0; i<n; i++) {
        cin >> temp;
        map[temp] = 1;
    }
    while(1) {
        temp = k++;
        while(temp>0) {
            if(map[temp%10] == 1)
                break;
            temp/=10;
        }
        if(temp == 0)
            break;
    }
    cout << k-1;
    return 0;
}
