
#include <iostream>
#include <string.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned ll
#define db double
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PII pair<int, int>

int N,d;

int main() {
    scanf("%d",&N);
    int lo=1,hi=10000;
    while (lo<hi) {
        int mid=(lo+hi)>>1;
        if (mid*(mid+1)<2*N) {
            lo=mid+1;
        } else {
            hi=mid;
        }
    }
    d=lo*(lo+1)/2-N;
    for (int i=1;i<=lo;i++) {
        if (i!=d) printf("%d ",i);
    }
    printf("\n");
}