#include<bits/stdc++.h>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    long long ans = 1e10;
    for (int i = 1; i < h; i++){
        long long a, b, c;
        a = (long long)i * w;
        if ((h - i) % 2 == 0 || w % 2 == 0) b = (long long)w * (h - i) / 2, c = b;
        else if (w != 1 && h - i != 1) b = ((long long)w * (h - i) + min(w, h - i)) / 2, c = ((long long)w * (h - i) - min(w, h - i)) / 2;
        else if (w != 1 || h - i != 1) b = ((long long)w * (h - i) + 1) / 2, c = ((long long)w * (h - i) - 1) / 2;
        else continue;
        ans = min(ans, max({a, b, c}) - min({a, b, c}));
    }
    swap(w, h);
    for (int i = 1; i < h; i++){
        long long a, b, c;
        a = (long long)i * w;
        if ((h - i) % 2 == 0 || w % 2 == 0) b = (long long)w * (h - i) / 2, c = b;
        else if (w != 1 && h - i != 1) b = ((long long)w * (h - i) + min(w, h - i)) / 2, c = ((long long)w * (h - i) - min(w, h - i)) / 2;
        else if (w != 1 || h - i != 1) b = ((long long)w * (h - i) + 1) / 2, c = ((long long)w * (h - i) - 1) / 2;
        else continue;
        ans = min(ans, max({a, b, c}) - min({a, b, c}));
    }
    cout << ans << endl;
}