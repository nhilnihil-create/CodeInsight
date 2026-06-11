#include<bits/stdc++.h>
using namespace std;
const int Max = (2e6) + 5,S = 1 << 21;
int n,a[Max],l,r;
int xchar() {
    static char ibuf[S];
    static int pos = 0,len = 0;
    if(pos == len) 
        pos = 0,len = fread(ibuf,1,S,stdin);
    if(pos == len) return EOF;
    return ibuf[pos++];
}
int read() {
    int c = xchar(),x = 0;
    while(!isdigit(c)) {
        c = xchar();
    }
    do
    {
        x = (x << 3) + (x << 1) + (c & 15);
        c = xchar();
    }while(isdigit(c));
    return x;
}
inline int check(int k){
    if((a[n+1] <= k && a[n] <= k) || (a[n] <= k && a[n-1] <= k))
        return 1;
    if((a[n+1] > k && a[n] > k) || (a[n] > k && a[n-1] > k))
        return 0;
    for(int i = 1;i < n-1;i++){
        if((a[n-i-1] <= k && a[n-i] <= k) || (a[n+i+1] <= k && a[n+i] <= k))
            return 1;
        if((a[n-i-1] > k && a[n-i] > k) || (a[n+i+1] > k && a[n+i] > k))
            return 0;
    }
    return k >= a[1];
}
int main() {
    n = read();
    for(int i = 1;i < (n << 1);++i)
        a[i] = read();
    l = 1;r = (n << 1) - 1;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid))
            r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}