# include <stdio.h>
int a[200000+3], n;
bool small(int i, int j, int k) {return a[i]<=k && a[j]<=k;}
bool big(int i, int j, int k) {return a[i]>k && a[j]>k;}
bool judge(int k)
{
    for(int i=0; i<n-1; ++i)
    {
        // if(big(n+i, n+i+1, k) || big(n-i, n-i-1, k)) return false;
        if ( ( a[n+i] > k && a[n+i+1] > k ) || ( a[n-i] > k && a[n-i-1] > k ) ) return false ;
        //if(small(n+i, n+i+1, k) || small(n-i, n-i-1, k)) return true;
        if ( ( a[n+i] <= k && a[n+i+1] <= k ) || ( a[n-i] <= k && a[n-i-1] <= k ) ) return true ;
    }
    //return small(1,1,k);
    return ( a[1] <= k && a[1] <= k ) ;
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<n<<1; ++i)
        scanf("%d",&a[i]);
    int l=1, r=(n<<1)-1, mid;
    while(l < r)
    {
        mid = l+r>>1;
        if(judge(mid))
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d\n",r);
    return 0;
}