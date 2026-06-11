 
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>
 
using namespace std;

const int N=100010;
int n;
int a[N];

int gcd(int x,int y) {
    return y==0?x:gcd(y,x%y);
}

bool lose() {
    int zero=0;
    int odd=0;
    int cnt=0;
    int idx=-1;
    bool flag=true;
    for (int i=1;i<=n;i++) {
        zero|=(a[i]-1);
        odd=(odd+a[i]-1)%2;
        if ((a[i]&1)&&(a[i]>1)) {
            cnt++;
            idx=i;
        }
        if (a[i]==1) flag=false;
    }
    if (zero==0) return true;
    if (odd) return false;
    if (cnt!=1||!flag) return true;
    a[idx]--;
    int tmp=a[1];
    for (int i=2;i<=n;i++) tmp=gcd(tmp,a[i]);
    for (int i=1;i<=n;i++) a[i]/=tmp;
    return !lose();
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
        scanf("%d",a+i);
    }
    if (n==1) {
        if ((a[1]-1)&1) printf("First\n");
        else printf("Second\n");
    } else {
        if (lose()) printf("Second\n");
        else printf("First\n");
    }
}