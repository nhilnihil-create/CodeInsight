#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    long long sum = 0LL;
    vector <int> a(n);
    for(int&i : a)
        scanf("%d",&i) ,sum += i;

    if((2*sum)%(n*(n+1LL))){
        cout << "NO" << endl;
        return 0;
    }

    int ops = 2*sum/n/(n+1) ,st = a[0];
    for(int i=0; i<n; i++)
        a[i] = -a[i]+(i<n-1? a[i+1] : st);

    int tot_end = 0;
    for(int&i : a){
        if((i+(n-1LL)*ops)%n || (i+(n-1LL)*ops)>1LL*n*ops){
            cout << "NO" << endl;
            return 0;
        }
        tot_end += ops-(i+(n-1LL)*ops)/n;
    }

    cout << (tot_end==ops? "YES" : "NO") << endl;
}
