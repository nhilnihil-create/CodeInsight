/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{   long long i,sum=0;
    string s;
    cin>>s;
    for(i=0;i<s.length();i++){
        if(s[i]=='g'&&i%2==0){;}
        else if(s[i]=='p'&&i%2!=0){;}
        else if(s[i]=='g'&&i%2!=0){sum+=1;}
        else{sum-=1;}
    }
    cout<<sum;
    return 0;
}
