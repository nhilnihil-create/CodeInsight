#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N,L,i;
    string S[101];
    cin>>N>>L;
    for (i=0;i<N;i++)
        cin>>S[i];
    sort(S,S+N);
    for (i=0;i<N;i++)
        cout<<S[i];
    return 0;
}
