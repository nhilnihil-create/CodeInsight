#include <bits/stdc++.h>
using namespace std;
//-------------------------↓↓↓↓↓↓------------------------

int main(void){
       cin.tie(0);
    ios::sync_with_stdio(false);

    long n, k, a[100000 + 10], b[100000 + 10], c, keta = 0, tmp, tmpp, ans, cnt = 0, pos;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }

    c = k;
    while(1){
        c /= 2;
        keta++;
        if(c == 0)break;
    }
    tmp = 0;
    for(int i = keta; i >= 0; i--){
        if((k & (1LL << i)) != 0){
            tmpp = 0;
            if(tmp < k){
                for(int j = 0; j < i; j++){
                    tmpp = (tmpp | (1LL << j));
                }
            }
            if((tmp | tmpp) <= k){
                pos = (tmp | tmpp);
            }
            else{
                pos = tmp;
            }
            if(i == 0)pos = k;
            for(int j = 0; j < n; j++){
                if((pos | a[j]) == pos)cnt += b[j];
            }
            ans = max(ans, cnt);
            tmp = (tmp | (k & (1LL << i)));
            cnt = 0;
        }
    }
    for(int i = 0; i < n; i++){
        if((k | a[i]) == k)cnt += b[i];
    }
    
    cout << max(ans, cnt) << "\n";
    return 0;
}
