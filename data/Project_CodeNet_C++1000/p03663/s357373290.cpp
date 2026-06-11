//created by missever

#include<bits/stdc++.h>
#define MAX 1000000007
using namespace std;
typedef long long LL;
typedef pair<int,int> P;

char s[105];
bool cput(LL x) {
    printf("? %lld\n",x);
    fflush(stdout);
    scanf("%s",s);
    return s[0] == 'Y';
}


int main() {
    int i,l = 0,r;
    bool vis = 1;
    for(i = 1000000000; i > 0; i /= 10) {
        if(cput(i)) {
            vis = vis & 1;
            if(l == 0) l = i;
        } else vis = 0;
    }
    if(vis) {
        for(i = 1; i <= 1000000000; i *= 10) {
            if(cput(i * 10LL - 1)) {
                printf("! %d\n",i);
                fflush(stdout);
                return 0;
            }
        }
    }
    r = l * 10 - 1;
    l  =l + 1;
    while(l < r) {
        int mid = (l + r) >> 1;
        if(cput(mid * 10LL + 1)) r = mid;
        else l = mid + 1;
    }
    printf("! %d\n",r);
    fflush(stdout);
    return 0;
}
