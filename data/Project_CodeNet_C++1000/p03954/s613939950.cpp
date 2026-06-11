#include <bits/stdc++.h>

using namespace std;

inline int read(){
    int AK = 1, IOI = 0;
    char ch = 0;
    while (ch < '0' || ch > '9'){
        AK = ch=='-'?-1:1;
        ch = getchar();
    }
    while (ch <= '9' && ch >= '0'){
        IOI *= 10;
        IOI += ch - 48;
        ch = getchar();
    }
    return AK * IOI;
}
int n;
inline int abs(int x){
    return x < 0 ? -x : x;
}
int a[1000001];
int b[1000001];

inline bool check(int x){
    for (int i = 1; i <= n * 2 - 1; i ++){
        b[i] = a[i] < x ? 0 : 1;
    }
    int Away_1 = 0x7f7f7f7f;
    int Away_0 = 0x7f7f7f7f;
    for (int i = 1; i <= n * 2 - 1; i ++){
        if (b[i] == b[i - 1]){
            if (b[i] == 1)
                Away_1 = std::min (Away_1, abs(i - n) + abs(i - 1 - n));
            else{
                Away_0 = std::min (Away_0, abs(i - n) + abs(i - 1 - n));
            }
        } 
    }
    if (Away_1 == Away_0 && Away_1 == 0x7f7f7f7f){
        return 1;
    }
    return Away_1 < Away_0;
}
int main(){
//    freopen("pyramid.in", "r", stdin);
//    freopen("pyramid.out", "w", stdout);
    n = read();
    int Min = 0x7f7f7f7f;
    int Max = 0;
    for (int i = 1; i <= n * 2 - 1; i ++){
        a[i] = read();
        Min = std::min (Min, a[i]);
        Max = std::max (Max, a[i]);
    }
    int left = Min, right = Max;
    int answer = 0;
    while (left <= right){
        int middle = (left + right) >> 1;
        if (check(middle)){
            answer = middle;
            left = middle + 1;
        } else{
            right = middle - 1;
        }
    }
    printf("%d", answer);
}