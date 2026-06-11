#include <bits/stdc++.h>
using namespace std;

int main()
{


    int n;
    cin>>n;

    int odd_cnt=0,even_cnt=0;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;

        if(a%2==0)
            even_cnt++;
        else
            odd_cnt++;
    }

    
    if(odd_cnt%2==1)
        cout<<"NO"<<endl;
    else
        cout<<"YES"<<endl;

    return 0;
}
