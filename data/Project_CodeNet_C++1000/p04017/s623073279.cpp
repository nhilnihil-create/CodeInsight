#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e5 + 5 ;

int lift[MAX][23] ;
int n , l ;
int arr[MAX] ;

void preprocess()
{
    lift[n][0] = n ;
    for(int i = 0 ; i < n ; ++i)
    {
        int idx = upper_bound(arr , arr + n , arr[i] + l) - arr ;
        idx-- ;
        if(arr[i] + l >= arr[n-1])
            idx = n ;
        lift[i][0] = idx ;
    }
    for(int j = 1 ; j < 23 ; ++j)
    {
        lift[n][j] = n ;
        for(int i = 0 ; i < n ; ++i)
        {
            lift[i][j] = lift[lift[i][j-1]][j-1] ;
            //cout<<i<<" "<<j<<" : "<<lift[i][j]<<"\n";
        }
    }
    return ;
}

int a , b ;

int query()
{
    int x = a ;
    int ans = 0 , ans2 = 1e9;
    for(int i = 21 ; i >= 0 ; --i)
    {
        if(lift[x][i] <= b)
            ans += (1 << i) , x = lift[x][i] ;
        else
            ans2 = min(ans2 , ans + (1 << i)) ;
    }
    if(x != b)
        ans++ ;
    return min(ans , ans2);
}

int main()
{
    scanf("%d" , &n) ;
    for(int i = 0 ; i < n ; ++i)
        scanf("%d" , &arr[i]) ;
    scanf("%d" , &l) ;
    preprocess() ;
    int q ;
    scanf("%d" , &q) ;
    while(q--)
    {
        scanf("%d %d" , &a , &b) ;
        if(a > b)
            swap(a , b);
        --a ;
        --b ;
        printf("%d\n" , query()) ;
    }
    return 0 ;
}
