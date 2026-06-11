#include<iostream>
#include<climits>
using namespace std;
int main()
{
    int n,s=0,mi=INT_MAX,i,j,c=0;
    cin>>n;
    int m[n];
    for(i=0;i<n;i++)
    {
        cin>>m[i];
    }
    for(i=0;i<n-1;i++)
    {
        if(m[i]==m[i+1])
        {
            c++;
        }
    }
    if(c==n-1)
    {
        cout<<"0"<<endl;

    }
    else{
    for(j=-105;j<=105;j++)
    {
        s=0;
        for(i=0;i<n;i++)
        {
            s=s+(m[i]-j)*(m[i]-j);
        }
        mi=min(mi,s);
    }

    cout<<mi<<endl;
    }
    return 0;
}
