#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define ll long long 
#define F(n) for(int i = 0; i < n; ++i)
#define Debug cout<<endl<<"I AM IRONMAN"<<endl

int main ()
{
    fastio;
    int n,ceven=0,codd=0;
    cin >> n;
    F(n)
    {
        int a;
        cin >> a;
        if(a%2==0)
        {
            ceven++;
        }
        else
        {
            codd++;
        }
       
    }
     if(codd%2==0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        

        
    return 0;
}