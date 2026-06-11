#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n, tmp, cnt, max_cnt = 0, max_num = 1;
    cin >> n;
    for (int i=1; i<=n; i++){
        tmp = i;
        cnt = 0;
        while (tmp % 2 == 0){
            cnt++;
            tmp /= 2;
        }
        if (max_cnt < cnt){
            max_cnt = cnt;
            max_num = i;
        }
    }
    cout << max_num << endl;
    return 0;
}