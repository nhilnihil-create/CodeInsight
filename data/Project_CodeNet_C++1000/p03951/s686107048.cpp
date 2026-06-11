#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,c=0;
    cin>>n;
    string s1,s2,temp;
    cin>>s1>>s2;
    for(int i=0;i<n;i++)
    {
        if(s1.substr(i,n)==s2.substr(0,n-i))
        {
            temp = s1.substr(0, i) + s2;
            int ans = temp.size();
            cout << ans << endl;
            return 0;
        }
    }
    cout<<2*n<<endl;
}