#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,K,X,Y,s1,s2=0;
    cin>>N>>K>>X>>Y;
    if(N<K)
    {
        K=N;
        s1=K*X;
    }
    else
     s1=K*X;

    s2=(N-K)*Y;
   cout<<s1+s2<<endl;


    return 0;
}
