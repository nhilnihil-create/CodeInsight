#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    int req=c%b;
    int rep=a%b;
    int temp=b,aa=a;
    if(a==1){
        cout<<"YES";
        return 0;
    }
    while(temp)
    {

        a+=aa;
        if(a%b==req){
            cout<<"YES\n";
            return 0;
        }
        if(a%b==rep){
            break;
        }
        temp--;
    }
    cout<<"NO";
    return 0;

}
