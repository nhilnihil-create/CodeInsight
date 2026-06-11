# include <iostream>
# include <algorithm>
using namespace std;

int N;
int a[300005];
long long sum=0;

bool descending (int a, int b)
{
    if (a>b)
    {
        return true;
    }

    return false;
}

int main()
{
    cin>>N;

    for (int i=1; i<=3*N; i++)
    {
        cin>>a[i];
    }

    sort(a+1, a+3*N+1, descending);

    for (int i=2; i<=2*N; i+=2)
    {
        sum=sum+a[i];
    }

    cout<<sum<<endl;
}