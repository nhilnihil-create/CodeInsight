#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

long int abs1(long int x){
    if (x > 0) return x;
    else return -x;
    
}

int main(){
    long int const INF = 10000000000000;
    long int h, w;
    cin >> h >> w;
    long int s = h * w;
    long int s1, s2;
    long int ans = INF;
    for (int i = 1; i < h; i++){
        long int sa = i * w;
        long int sb = ((h - i) / 2) * w;
        long int sc = ((h - i) / 2 + (h - i) % 2) * w;
        s1 = max(abs1(sa - sb), max(abs1(sb - sc), abs(sc - sa)));
        sb = (h - i) * (w / 2);
        sc = (h - i) * (w / 2 + w % 2);
        s2 = max(abs1(sa - sb), max(abs1(sb - sc), abs(sc - sa)));
        if (h == 2){
            s1 = INF;
        }
        
        ans = min(ans, min(s1, s2));
    }
    for (int i = 1; i < w; i++){
        long int sa = i * h;
        long int sb = ((w - i) / 2) * h;
        long int sc = ((w - i) / 2 + (w - i) % 2) * h;
        s1 = max(abs1(sa - sb), max(abs1(sb - sc), abs(sc - sa)));
        sb = (w - i) * (h / 2);
        sc = (w - i) * (h / 2 + h % 2);
        s2 = max(abs1(sa - sb), max(abs1(sb - sc), abs(sc - sa)));
        if (w == 2){
            s2 = INF;
        }
        ans = min(ans, min(s1, s2));
    }
    cout << ans << endl;
}