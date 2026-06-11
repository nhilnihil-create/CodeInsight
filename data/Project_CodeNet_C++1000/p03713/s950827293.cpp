#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); i++)
int main()
{
    long long h, w;
    cin >> h >> w;

    long long s[3], smin1, smin2, tmp, ans = INT_MAX;
    for(int i = 1; i <= h; i++){
        s[0] = i * w;
        s[1] = ((h - i) / 2) * w;
        if((h-i)%2==0){
            s[2] = s[1];
        }
        else{
            s[2] = ((h - i) / 2 + 1) * w;
        }
        sort(s, s+3);
        smin1 = s[2] - s[0];

        s[0] = i * w;
        s[1] = (h - i) * (w / 2);
        if(w%2==0){
            s[2] = s[1];
        }
        else{
            s[2] = (h - i) * (w / 2 + 1);
        }
        sort(s, s+3);
        smin2 = s[2] - s[0];

        tmp = min(smin1, smin2);
        ans = min(ans, tmp);
    }

    for(int i = 1; i <= w; i++){
        s[0] = i * h;
        s[1] = ((w - i) / 2) * h;
        if((w-i)%2==0){
            s[2] = s[1];
        }
        else{
            s[2] = ((w - i) / 2 + 1) * h;
        }
        sort(s, s+3);
        smin1 = s[2] - s[0];

        s[0] = i * h;
        s[1] = (w - i) * (h / 2);
        if(h%2==0){
            s[2] = s[1];
        }
        else{
            s[2] = (w - i) * (h / 2 + 1);
        }
        sort(s, s+3);
        smin2 = s[2] - s[0];

        tmp = min(smin1, smin2);
        ans = min(ans, tmp);
    }

    cout << ans;

    return 0;
}