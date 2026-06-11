#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

int main()
{
 

    long Q,H,S,D;
    cin>>Q>>H>>S>>D;

    long N;
    cin>>N;

    // unit price, litter
    vector<tuple<long, double> > tuples(4);

    tuples.at(0)=make_tuple(Q*4,0.25);
    tuples.at(1)=make_tuple(H*2,0.5);
    tuples.at(2)=make_tuple(S,1);
    tuples.at(3)=make_tuple(D/2,2);

    sort(tuples.begin(),tuples.end());

    if(get<1>(tuples.at(0)) ==2){
        cout<<N/2*D+N%2*get<0>(tuples.at(1))<<endl;
    }
    else {
        cout<<N*get<0>(tuples.at(0))<<endl;
    }

    return 0;
}