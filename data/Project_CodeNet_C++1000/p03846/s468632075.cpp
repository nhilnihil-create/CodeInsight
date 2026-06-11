#include<bits/stdc++.h>
using namespace std;
int m = 1e9+7;
int main ()
{
    int n,i;
    long long int ans =1;
    cin >> n;
    vector <int> a(n);
    fill (a.begin(),a.end(),0);
    int temp = n;
    while (temp--)
    {
        cin >> i;
        a[i]++;
    }
    if (n%2)
    {
        if (a[0]!= 1)
        {
            cout << "0\n";
            return 0;
        }
        for ( i =1 ; i<n; i++)
        {
            if(i%2&& a[i]!=0)
            {
                cout << "0\n";
                return 0;
            }
            if(i%2 == 0)
            {
                if (a[i]!= 2)
                {
                    cout << "0\n";
                    return 0;
                }
                else
                {
                    ans = (ans *2 ) % m;
                }
            }
        }
    }
    else{
        if (a[0]!= 0){ cout << "0\n"; return 0;}
        for ( i =1 ; i< n ; i++){
            if (i%2 == 0 && a[i]!= 0){cout << "0\n"; return 0;}
            else if (i%2){
                if(a[i]!= 2){cout << "0\n"; return 0;}
                ans = ans*2%m;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
