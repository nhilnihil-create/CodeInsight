#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

int main()
{
    int n, i, ans1 = 0, ans, sum = 0;
    // float mean1;
    int mean;
    cin >> n;
    int a[n];
    for(i=0;i<n;i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    mean = sum/n;
    for(i=0;i<n;i++)
    {
        ans1 += (a[i] - mean)*(a[i] - mean);
    }
    ans = ans1;
    mean = mean + 1;
    ans1 = 0;
    for(i=0;i<n;i++)
    {
        ans1 += (a[i] - mean)*(a[i] - mean);
    }
    ans = min(ans1, ans);
    cout << ans;
    return 0;
}