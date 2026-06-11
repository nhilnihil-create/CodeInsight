#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    
    int a,b,c;
    cin>>a>>b>>c;

    if(c>=a && c<=b){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

}
