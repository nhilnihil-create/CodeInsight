# include <iostream>
using namespace std;

int N;
int A;
int counter=0;

int main()
{
    cin>>N;

    for (int i=0; i<N; i++)
    {
        cin>>A;

        if (A%2==1)
        {
            counter++;
        }
    }

    if (counter%2==0)
    {
        cout<<"YES"<<endl;
    }

    else
    {
        cout<<"NO"<<endl;
    }
}