# include <iostream>
# include <cstring>
using namespace std;

int N;
int P; //even or odd//
int A[55];
long long memo[5005][55];

long long bags (long long biscuits, long long bag)
{
    if (memo[biscuits][bag]!=-1)
    {
        return memo[biscuits][bag];
    }

    if (bag>N && biscuits%2==P)
    {
        return memo[biscuits][bag]=1;
    }

    if (bag>N && biscuits%2!=P)
    {
        return memo[biscuits][bag]=0;
    }

    long long sum=0;

    return memo[biscuits][bag]=bags(biscuits+A[bag], bag+1)+bags(biscuits, bag+1);
}

int main()
{
    memset(memo, -1, sizeof(memo)); 

    cin>>N>>P;

    for (int i=1; i<=N; i++)
    {
        cin>>A[i];
    }

    cout<<bags(0, 1)<<endl;
}