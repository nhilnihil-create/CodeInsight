#include <bits/stdc++.h>
using namespace std;

long long gcd(long x, long y)
{    if (y == 0)
        return x;
    return gcd(y, x % y);}
long long lcm(long x, long y){ return x * y / gcd(x, y);}

int ctoi(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    return 0;
}


int main()
{
    int N,M,K;
    cin>>N>>M>>K;

    for(int i=0;i<=N;i++){
        for(int j=0;j<=M;j++){

            int a=(N-i)*j+i*(M-j);

            if(K==a||K==(N*M-a)){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }

    cout<<"No"<<endl;

    return 0;
}