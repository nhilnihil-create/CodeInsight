#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin>>n;
    int s[n];
    int sum =0;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
        sum += s[i];
    }
    sort( s,s+n);
    bool answered = false;
    if(sum%10!= 0 )
    {
        cout<<sum;
        answered = true;
    } else {
        for (int i = 0; i < n; i++) {
            if ( (sum - s[i]) % 10 != 0) {
                cout << sum - s[i];
                answered = true;
                break;
            }
        }
    }
    if( !answered )
        cout<<0;
}