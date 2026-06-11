#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,k;
    cin >> t;
    k=t;
    vector <int> side(t);
    int n;
    int p=0;
    while(k--)
    {
        cin>>side[p++];
    }
    sort(side.begin(),side.end(),greater<int>());
    int a=0,b=0,i,f=0;
    for(i=0;i<t-1;i++)
    {
        if(side[i]==side[i+1])
        {
            if(f==0){
                a=side[i];
                f++;
            }
            else if(f==1){
                b=side[i];
                f++;
            }
            i++;
        }
       // if(a>0 && b>0) break;
    }
    cout << a*1LL*b << endl;
}
