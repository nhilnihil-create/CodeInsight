# include <iostream>
# include <algorithm>
using namespace std;

int N;
int A[100005];
long long prefixsum[100005];
long long counter=1;

int main()
{
    cin>>N;
    
    for (int i=1; i<=N; i++)
    {
        cin>>A[i];
    }

    sort(A+1, A+N+1);

    for (int i=1; i<=N; i++)
    {
        prefixsum[i]=prefixsum[i-1]+A[i];
    }

    for (int i=N; i>=1; i--)
    {
        if (i!=N)
        {
            if(prefixsum[i]*2>=A[i+1])
            {
                counter++;
            }

            else
            {
                break;
            }
        }
    }

    cout<<counter<<endl;
}



