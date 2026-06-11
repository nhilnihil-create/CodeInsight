#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long int N;
    cin>>N;
    long long int L[2*N];

    for(int x = 0;x<2*N;x++){
        cin>>L[x];
    }
    sort(L,L+2*N);

    long long int Ans = 0;

    for(int x = 0;x<2*N;x+=2){
        Ans+=L[x];

    }
    cout<<Ans<<"\n";

}
