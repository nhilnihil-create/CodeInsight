#include<bits/stdc++.h>
#define ll long long int
using namespace std;



int main()
{
    ll t,c=0;
        ll n,b,a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,x=0;
        cin>>n;
        //ll l1[n+1];
        for(int i=1;i<=n;i++){
            cin>>b;
            if(b>=1&&b<=399&&a1==0)a1++;
            else if(b>=400&&b<=799&&a2==0)a2++;
            else if(b>=800&&b<=1199&&a3==0)a3++;
            else if(b>=1200&&b<=1599&&a4==0)a4++;
            else if(b>=1600&&b<=1999&&a5==0)a5++;
            else if(b>=2000&&b<=2399&&a6==0)a6++;
            else if(b>=2400&&b<=2799&&a7==0)a7++;
            else if(b>=2800&&b<=3199&&a8==0)a8++;
            else if(b>=3200)x++;
        }
        ll s,mi,ma;
        s=a1+a2+a3+a4+a5+a6+a7+a8;
        //cout<<s<<endl;
        //cout<<x<<endl;
        if(n-x>0)mi=s;
        else mi=1;
        ma=x+s;
        cout<<mi<<" "<<ma<<endl;

    return 0;
}
