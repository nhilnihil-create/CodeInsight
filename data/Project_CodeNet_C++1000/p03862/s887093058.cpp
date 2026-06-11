#include <iostream>
using namespace std;

int main()
{
	long long n, x, a[100010], cnt=0, sum;
	cin >> n >> x;
	for(int i = 0; i < n; i++)cin >>a[i];
	for(int i = 1; i < n; i++)
    {
        sum = a[i-1]+a[i];
        if(sum>x)
        {
            sum-=x;
            if(sum>a[i])a[i]=0, a[i-1]-=sum-a[i];
            else        a[i]-=sum;
            cnt+=sum;
        }
    }
    cout << cnt << endl;
}
