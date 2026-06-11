#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main()
{
    long long n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    bool chk[2][52];
    memset(chk,0,sizeof(chk));
    long long colors=1;
    int c=2;
    for(int i=0; i<n; i++)
    {

        if(i+1<n&&s1[i]==s1[i+1])
        {
            // int c;

            // cout<<s1[i]<<" "<<s1[i+1] <<" "<<c<<endl;
            if(i==0)c=6;
            else c=c+1;

            colors*=c;

            colors%=MOD;
            c=2;
            chk[0][i]=1;
            chk[0][i+1]=1;
            chk[1][i]=1;
            chk[1][i+1]=1;
            i++;
        }

        else if(s1[i]==s2[i])
        {
           // int c;
            if(i==0)
                c=3;
            if(i!=0&&s1[i-1]==s2[i-1])
            {
                c=2;

            }


            else if(i!=0)
                c=1;
            colors=(colors*c)%MOD;
            c=1;
            chk[0][i]=1;
            chk[1][i]=1;
          //  cout<<s1[i]<<" "<<s1[i] <<" "<<c<<endl;
        }
    }
    cout<<colors<<endl;
    //main();
}
