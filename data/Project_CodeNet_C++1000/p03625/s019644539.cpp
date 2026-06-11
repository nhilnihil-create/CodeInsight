#include<bits/stdc++.h>
using namespace std;
long long int a[100100], i, n, temp, width, height;
int main()
{
    cin >> n;
    for(i=0;i<n;i++)
        cin >> a[i];
    sort(a, a+n);
    for(i=0;i<n-1;i++)
    {
        if(a[i]==a[i+1])
        {
            temp = height;
            height = a[i+1];
            width = temp;
            i++;
        }
    }
    cout << height*width<< endl;
}
