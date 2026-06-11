# include <iostream>
using namespace std;

long long N;
long long A;
long long B;

int main()
{
    cin>>N>>A>>B;

    if (A>B)
    {
        cout<<0<<endl;
        return 0;
    }

    if (N==1 && A==B)
    {
        cout<<1<<endl;
        return 0;
    }

    if (N==1 && A!=B)
    {
        cout<<0<<endl;
        return 0;
    }

    long long lowerbound=(N-1)*A+B;
    long long upperbound=(N-1)*B+A;

    long long ans=upperbound-lowerbound+1;

    cout<<ans<<endl;
}