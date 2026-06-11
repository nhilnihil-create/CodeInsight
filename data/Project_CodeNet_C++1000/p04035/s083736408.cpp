#include <iostream>
using namespace std;

int main()
{
    int N, cut;
    long long int L, prev, curr;
    bool poss=false;
    cin>>N>>L;
    for(int i=0; i<N; i++)
    {
        cin>>curr;
        if(i==0) prev=curr;
        else
        {
            if(prev+curr>=L)
            {
                cut=i;
                poss=true;
            }
        }
        prev=curr;
    }
    if(poss==false) cout<<"Impossible"<<endl;
    else
    {
        cout<<"Possible"<<endl;
        for(int i=1; i<cut; i++) cout<<i<<endl;
        for(int i=N-1; i>cut; i--) cout<<i<<endl;
        cout<<cut<<endl;
    }
}