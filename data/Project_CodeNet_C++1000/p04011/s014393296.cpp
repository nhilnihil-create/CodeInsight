#include<bits/stdc++.h>
using namespace std;
int main()
{
int N,K,X,Y, s;
cin>>N>>K>>X>>Y;
if(N<K)
{s=N*X;
}
else
s=(K*X)+((N-K)*Y);

cout<<s;
return 0;
}
