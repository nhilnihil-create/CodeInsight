#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

typedef long long LL;

bool ask(LL n) {
    printf("? %lld\n",n);
    fflush(stdout);
    char ans;
    scanf(" %c", &ans);
    if (ans == 'Y') return true;
    else return false;
}

int Sz(LL x) {
    int ret=0;
    while (x>0) {
        ret++;
        x/=10;
    }
    return ret;
}

LL pow(LL a,LL n) {
    LL ret=1;
    for (int i=0;n>i;i++) ret*=a;
    return ret;
}

int main () {
    //cout<<("11" < "110" )<<endl;
    LL haha=100000LL * 1000000LL;
    LL now=0;
    int lastR=0;
    for (int i=1;10>=i;i++) {
        //test the i-th digit
        now*=10;
        int L=-1,R=10;
        haha/=10;
        while (R-L!=1) {
            int mid=(L+R)>>1;
            if(i==1 && mid==0) {
                R=1;
                L=0;
                break;
            }
            if (ask((now+mid)*haha + (haha-1))) R=mid;
            else L=mid;
        }
        now+=R;
        //lastR = R;
    }
    map<LL,bool> mp;
    int _=0;
    for (LL i=1;;i*=10) {
        _++;
        mp[i]=1;
        if (_>11) break;
    }
    //cout<<"now = "<<now<<endl;
    while (1) {
        if (now%10 != 0) break;
        //deal with 999 and 9990 first
        if (mp[now/10+1] == true) {
            if (ask(now/10+1) == true) break;
            else now/=10;
        }
        else if (ask( pow(10,Sz(now)-1) - 1) == true) now/=10;
        else break;
    }
    int ans=now;
    printf("! %d\n",ans);
    fflush(stdout);
    return 0;
}

