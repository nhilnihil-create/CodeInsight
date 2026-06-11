#include<bits/stdc++.h>
using namespace std;
main()
{

                long long A,B,C,k=0,j=0;
                cin>>A>>B>>C;
                if(A==5){
                                k++;
                }
                else{
                                j++;
                }
                 if(B==5){
                                k++;
                }
                else{
                                j++;
                }
                   if(C==5){
                                k++;
                }
                else{
                                j++;
                }
                if(k==2&&j==1)
                {
                                cout<<"YES"<<endl;
                }
                else{
                                cout<<"NO"<<endl;
                }


}
