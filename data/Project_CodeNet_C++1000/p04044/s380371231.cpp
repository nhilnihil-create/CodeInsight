#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    int N,L,i,j,d;
    cin>>N>>L;
    string s[N];
    for(i=0;i<N;i++)
    {
        cin>>s[i];
    }
    sort(s,s+N);
    for(i=0;i<N;i++)
    {
        cout<<s[i];
    }
    cout<<endl;
}
