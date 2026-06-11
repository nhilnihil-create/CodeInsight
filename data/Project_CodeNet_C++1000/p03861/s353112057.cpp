#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    //int t;

    unsigned long long a,b,x,res;

    //cin>>t;

    //while(true){

        cin>>a>>b>>x;

        res = (b-a+1)/x;

        //cout<<"\nres f = "<<res<<" ";

        //if(a!=b){
            a+=res*x;
            //cout<<"a = "<<a<<"\n";
        //}

        if(a<=b){
            if(a==b && a%x==0)
                res++;

            else if( a%x > b%x || a%x==0 )
                res++;
        }

        cout<<res<<endl;
   //}

    return 0;
}