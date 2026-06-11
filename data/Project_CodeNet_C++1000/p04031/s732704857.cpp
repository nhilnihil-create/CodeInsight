#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if(n>=1 && n<=100)
    {
        int a[n];
        int flag = 1;
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
            if(a[i]<-100 || a[i]>100)flag = 0;
        }
        if(flag)
        {
            int finalans=0;
            int sum = 0;
            for(int i=0; i<n; i++)
            {
                sum += a[i];
            }
            float mean = 1.0*sum/n;
            if((mean - floor(mean))>0.5)
            {
                for(int i=0; i<n; i++)
                {
                    finalans += (ceil(mean)-a[i])*(ceil(mean)-a[i]);
                }
            }
            else {
                for(int i=0; i<n; i++)
                {
                    finalans += (floor(mean)-a[i])*(floor(mean)-a[i]);
                }
            }
            cout << finalans << endl;
        }
    }
    return 0;
}
