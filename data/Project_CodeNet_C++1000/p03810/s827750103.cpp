# include <iostream>
# include <vector>
# include <deque>
# include <math.h>
# include <set>
# include <iomanip>
# include <time.h>
# include <list>
# include <stdio.h>
# include <queue>
# include <map>
# include <algorithm>
# include <string.h>

# define ll long long
# define mk make_pair
# define sc second
# define fr first
# define pb push_back

using namespace std;

const long long N = (1e6 + 10);
const long long mod = (1e9 + 7);

int n,k,a[N],g;

int f(int sign){
    int k = 0,g = 0;
    for(int i = 1; i <= n; i ++)
        k += (a[i] % 2);

    if((n - k) & 1)
        return sign;

    if(k > 1)
        return sign ^ 1;

    else{
        for(int i = 1; i <= n; i ++){
            if(a[i] == 1)
                return sign ^ 1;

            if(a[i] & 1)
                a[i] --;
            if(g == 0)
                g = a[i];
            else
                g = __gcd(g,a[i]);
        }

        for(int i = 1; i <= n; i ++)
            a[i] /= g;

        return f(sign ^ 1);
    }
}
main () {
    scanf("%d", &n);

    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);

    printf(f(1) == 1 ? "First" : "Second");
}
