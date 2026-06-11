//BISMILLAHIR RAHMANIR RAHIM
//SOTO MEAW
//SOTO SONDESH
#include<bits/stdc++.h>

#define ls ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define __ <<" "<<
#define case(z) "Case " << z++ << ": "
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define quit return 0

using namespace std;

void showmyDS(set<int> ds)
{
    set<int> ::iterator it;
    for (it=ds.begin();it!=ds.end();it++)
    {
        cout << *it << endl ;
    }
    cout << endl;
}
int main()
{
    ls
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    //int t,l=1;cin>>t;while(t>0){
        int n,i,a=0,b=0;
        for(i=1;i<=3;i++)
        {
            cin >> n ;
            if(n==5)
                a++;
            else if(n==7)
                b++;
        }
        if(a==2 && b==1)
            cout << "YES" ;
        else
            cout << "NO" ;
    //t--;}

    quit;
}
