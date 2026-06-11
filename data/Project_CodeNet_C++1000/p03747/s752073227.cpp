#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;
static const int MAX = 100010;

int read(){
    char ch = getchar();
    int f = 1, x = 0;
    while(ch-'0' < 0 || ch-'0' > 9){if (ch == '-') f = -1; ch = getchar();}
    while(ch-'0' >= 0 && ch-'0' <= 9){x = x*10 + ch-'0'; ch = getchar();}

    return f * x;
}

int n, l, t;
int pos[MAX];

int main(){
    n = read(); l = read(); t = read();
    
    int tmp = 0;
    for (int i = 0; i < n; i++){
        int x = read(), w = read();
        if (w == 1){
            pos[i] = (x + t) % l;
            tmp += (x + t) / l;
        }else{
            pos[i] = (x - t) % l;
            tmp += (x - t) /l;
            if (pos[i] < 0){
                pos[i] += l;
                tmp--;
            }
        }
    }

    tmp = ((tmp % n) + n) % n;
    sort(pos, pos + n);

    for (int i = tmp; i < n; i++) cout << pos[i] << endl;
    for (int i = 0; i < tmp; i++) cout << pos[i] << endl;

    return 0;
}
