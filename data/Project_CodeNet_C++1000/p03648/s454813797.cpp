#include <iostream>
using namespace std;
int main()
{
    long long c[51];
    long long k,a,b;
    int j=0;
    scanf("%lld",&k);
    a=k/50;
    b=k%50;
    cout<<"50"<<endl;
    if(k%50==0)
	{
        for(long long i=50+a-1;i>=a;i--)
            cout<<i<<" ";
    }
    else
	{
        for(long long i=50+a;i>=a;i--)
		{
            c[j]=i;
            j++;
        }
        for(long long i=0;i<51;i++)
		{
            if(i==b)
                continue;
            else
                cout<<c[i]<<" ";
        }
    }
    cout<<endl;
    return 0;
}
/*
    49 48 47.........0    K=0
50     48 47.........0    K=1
50  49    47.........0    K=2
    50 49 48.........1    K=50
*/