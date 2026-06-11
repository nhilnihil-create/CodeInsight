/*
~Like a small boat
~On the ocean
~Sending big waves
~Into motion
!Like how a single word
!Can make a heart open
!I might only have one match
!But I can make an explosion
#And all those things I didn't say
#Wrecking balls inside my brain
#I will scream them loud tonight
#Can you hear my voice this time?
@This is my fight song
@Take back my life song
@Prove I'm alright song
@My power's turned on
$Starting right now I'll be strong
$I'll play my fight song
$And I don't really care if nobody else believes
$'Cause I've still got a lot of fight left in me!!!
*/

#include "bits/stdc++.h"
using namespace std;

#define  F  first
#define  S  second
#define  pb push_back
#define  mp make_pair
#define  sz(s) (int)s.size()
typedef long long int ll;
const int N = 1e5+5;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n,m;cin>>n>>m;
    bool F = 0;
    ll Arr[m+2],A=-1,B=-1;
    for(int i=1;i<=m;i++)
    {
        cin>>Arr[i];
        if( Arr[i]&1 )
        {
            if( A==-1 )A = i;
            else if( B==-1 )B = i;
            else F = 1;
        }
    }
    if( F )cout<< "Impossible\n";
    else
    {
        if( m==1 )
        {
            if( Arr[1]==1 )cout<< "1\n1\n1\n";
            else cout<<Arr[1]<<"\n"<<"2\n"<<"1 "<<Arr[1]-1<< "\n";
        }
        else
        {
            if( A!=-1 )swap(Arr[1],Arr[A]);
            if( B!=-1 )swap(Arr[m],Arr[B]);
            for(int i=1;i<=m;i++)
            {
                if(i>1)cout<< " ";
                cout<<Arr[i];
            }
            cout<< "\n";
            Arr[1]++,Arr[m]--;
            if(Arr[m])cout<<m<< "\n";
            else cout<<m-1<< "\n";
            for(int i=1;i<=m;i++)
            {
                if( Arr[i] )
                {
                    if( F )cout<< " ";
                    cout<<Arr[i];
                    F = 1;
                }
            }
            cout<< "\n";
        }
    }




    return 0;
}
