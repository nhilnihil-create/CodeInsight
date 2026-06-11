#include <stdio.h>
#include <string.h>
#include <math.h>
long long int gcd (long long int a,long long int b) {
    return (b?gcd(b,a%b):a);

}
int main ()
{
    long long int n, k, c=0, gcd2;
    scanf ("%lld %lld", &n, &k);
    long long int a[n];
    for (long long int i=0;i<n;i++) {
        scanf ("%lld", &a[i]);
        if (k<=a[i])c=1;
        if (i==0) gcd2 = a[i];
        else gcd2 = gcd(gcd2, a[i]);
    }
    if (k%gcd2==0 && c==1) printf ("POSSIBLE");
    else printf ("IMPOSSIBLE");
    return 0;
}
