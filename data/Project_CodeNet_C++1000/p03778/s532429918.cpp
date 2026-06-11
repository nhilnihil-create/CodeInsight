#include <bits/stdc++.h>

using namespace std;

int W,a,b,FV,SV,zero;

int main() {
    cin>>W>>a>>b;
    zero=0;
    FV=b-(W+a);
    SV=a-(W+b);
    {if(FV>zero)
     cout<<FV<<endl;
     else if(SV>zero)
     cout<<SV<<endl;
     else
     cout<<zero<<endl;
    }
           }
