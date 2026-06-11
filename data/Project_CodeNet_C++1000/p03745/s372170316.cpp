# include <iostream>
using namespace std;

int N;
int A[100005];
int flag=0; //-1 descending, 0 neutral, 1 ascending
int counter=1;

int main()
{
    cin>>N;

    for (int i=1; i<=N; i++)
    {
        cin>>A[i];
    }

    for (int i=2; i<=N; i++)
    {


        if (A[i]>A[i-1] && flag==-1)
        {
            flag=0;
            counter++;
        }
        
        else if (A[i]<A[i-1] && flag==1)
        {
            flag=0;
            counter++;
        }

        else if (flag==0 && A[i]>A[i-1])
        {
            flag=1;
        }

        else if (flag==0 && A[i]<A[i-1])
        {
            flag=-1;
        }

    }

    cout<<counter<<endl;
}