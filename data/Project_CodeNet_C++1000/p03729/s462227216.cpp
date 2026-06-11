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

    string a,b,c;
    cin>>a>>b>>c;

    if(*(a.end()-1) == *b.begin() && *(b.end()-1) == *c.begin()){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

}
