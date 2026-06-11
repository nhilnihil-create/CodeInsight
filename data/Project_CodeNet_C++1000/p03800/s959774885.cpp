#include<iostream>

using namespace std;

int S[100005],A[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        char c;
        cin>>c;
        if(c=='o')
            A[i]=0;
        else
            A[i]=1;
    }

    bool ok=0;
    for(int i=0; i<4; i++)
    {
        S[0]=i%2;
        S[1]=(i/2)%2;

        for(int j=1; j<n; j++)
        {
            int cr;
            if(S[j]==0)
                cr=A[j];
            else
                cr=1-A[j];

            if(cr==0)
                S[j+1]=S[j-1];
            else
                S[j+1]=1-S[j-1];
        }

        int cr;
        if(S[n-1]==0)
            cr=A[n-1];
        else
            cr=1-A[n-1];

        bool ok1=0;
        if(cr==0)
        {
            if(S[0]==S[n-2])
                ok1=1;
        }
        else
        {
            if(S[0]!=S[n-2])
                ok1=1;
        }

        if(!ok1)
            continue;

        if(S[0]==0)
            cr=A[0];
        else
            cr=1-A[0];

        if(cr==0)
        {
            if(S[1]==S[n-1])
            {
                ok=1;
                break;
            }
        }
        else
        {
            if(S[1]!=S[n-1])
            {
                ok=1;
                break;
            }
        }
    }

    if(!ok)
    {
        cout<<"-1\n";
        return 0;
    }

    for(int i=0; i<n; i++)
    {
        if(S[i]==0)
            cout<<'S';
        else
            cout<<'W';
    }
    cout<<"\n";
    return 0;
}
