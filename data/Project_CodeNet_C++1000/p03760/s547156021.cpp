#include <bits/stdc++.h>
using namespace std;
using ll=long long;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    string O,E,p;

    cin>>O>>E;

    int a=O.length();
    int b=E.length();

    for(int i=0;i<(a+b);i++){
        if(i&1){
            p+=E[i/2];
        }else{
            p+=O[i/2];
        }
    }

    cout<<p<<endl;

}
