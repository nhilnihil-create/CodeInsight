# include <iostream>
# include <algorithm>
using namespace std;

int N; 
int C;
int K;
int T[100005];
int buses=1;
int passengers=0;
int first=-1;

int main()
{
    cin>>N>>C>>K;

    for (int i=0; i<N; i++)
    {
        cin>>T[i];
    }

    sort(T, T+N);

    passengers=1;
    first=T[0];

    for (int i=1; i<N; i++)
    {
        if (passengers<C && T[i]<=first+K)
        {
            passengers++;
        }
        
        else
        {
            buses++;
            first=T[i];
            passengers=1;
        }
    }

    cout<<buses<<endl;
}