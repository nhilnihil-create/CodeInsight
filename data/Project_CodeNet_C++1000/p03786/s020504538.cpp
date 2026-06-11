#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector <long long> a(n);
    for(auto&i : a)
        scanf("%d",&i);
    sort(a.begin() ,a.end());
    for(int i=1; i<n; i++)
        a[i] += a[i-1];
    for(int i=n-2; ~i; i--)
        if(2*a[i] < a[i+1]-a[i]){
            cout << n-i-1 << endl;
            return 0;
        }
    cout << n << endl;
}
