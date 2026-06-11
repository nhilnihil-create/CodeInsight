#include <stdio.h>
#include <algorithm>
#include <vector>
 
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>
 
using namespace std;
 
ll p10[15];
int nbits=-1;
char a[2],b[2],c[2],d[2];
int num[15];
 
ll get(int n) {
    ll ret=0;
    for (int i=0;i<n;i++) {
        ret=ret*10+num[i];
    }
    return ret;
}
 
int main() {
    p10[0]=1;
    for (int i=1;i<13;i++) p10[i]=p10[i-1]*10;
/*
    printf("? 1\n");fflush(stdout);
    scanf("%s",a);
    printf("? 9\n");fflush(stdout);
    scanf("%s",b);
    for (int i=2;i<11;i++) {
        printf("? %lld\n",p10[i-1]);fflush(stdout);
        scanf("%s",c);
        printf("? %lld\n",p10[i]-1);fflush(stdout);
        scanf("%s",d);
        if (a[0]!=c[0]||b[0]!=d[0]) {
            if (c[0]=='Y') nbits=i;
            else nbits=i-1;
            break;
        }
        a[0]=c[0];b[0]=d[0];
    }
    //printf("nbits:%d\n",nbits);
    for (int i=0;i<15;i++) num[i]=9;
    for (int i=0;i<nbits;i++) {
        int lo=(i==0)?1:0;
        int hi=9;
        while (lo<hi) {
            int mid=(lo+hi)>>1;
            num[i]=mid;
            printf("? %lld\n",get(nbits+1));fflush(stdout);
            scanf("%s",a);
            if (a[0]=='Y') hi=mid;
            else lo=mid+1;
        }
        num[i]=lo;
    }*/
    for (int i = 0; i <= 10; i++) {
        printf("? %lld\n",p10[i]);fflush(stdout);
        scanf("%s",a);
        if (a[0] == 'N') {
            nbits = i;
	    break;
        }
    }
    if (nbits == -1) {
        for (int i = 1; i <= 10; i++) {
            printf("? %lld\n",p10[i]+1);fflush(stdout);
            scanf("%s",a);
            if (a[0]=='Y') {
                nbits = i + 1;
		break;
            }
        }
        if (nbits == 2) {
            printf("? 2\n");fflush(stdout);
            scanf("%s",a);
            if (a[0] == 'Y') {
                nbits = 1;
            }
        }
    }
    ll lo=p10[nbits-1],hi=p10[nbits]-1;
    while (lo<hi) {
        ll mid=(lo+hi)>>1;
        printf("? %lld\n",mid*10);fflush(stdout);
        scanf("%s",a);
        if (a[0]=='Y') hi=mid;
        else lo=mid+1;
    }
    printf("! %lld\n",lo);fflush(stdout);
}