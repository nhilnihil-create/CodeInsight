#include<cstdio>
#include<iostream>

#define REP(i,n)   for(int i=0;i<(n);++i)

using namespace std;

template<typename ...> static inline int getchar_unlocked(void) {
    return getchar();
}
#define mygc(c) (c)=getchar_unlocked()

void reader(int& x) {
    int k, m = 0; x = 0;
    for (;;) {
         mygc(k);
         if (k == '-') { m = 1; break; }
         if ('0' <= k&&k <= '9') {
             x = k - '0';
             break;
         }
     }
     for (;;) {
         mygc(k);
         if (k<'0' || k>'9') break;
         x = x * 10 + k - '0';
     }
     if (m) x = -x;
 }

 int a[100000];

int main(){
    int n,m,min=1234567899,d=0,cnt=0;
    reader(n);
    reader(m);
    REP(i,n) reader(a[i]);
    REP(i,n){
        if(min>a[i]){
            min = a[i];
        }else if(d==a[i]-min){
            ++cnt;
        }else if(d<a[i]-min){
            d = a[i] - min;
            cnt=1;
        }
    }
    printf("%d",cnt);
    return 0;
}
