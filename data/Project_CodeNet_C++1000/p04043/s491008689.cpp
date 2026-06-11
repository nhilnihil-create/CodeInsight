#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b , c;
    cin>>a>>b>>c;
    
    int c1 = 0;
    int c2 = 0;
    if(a==5)
    c1++;
    else if(a==7)
    c2++;
    
     if(b==5)
    c1++;
    else if(b==7)
    c2++;
    
     if(c==5)
    c1++;
    else if(c==7)
    c2++;
    
    if(c1 == 2 && c2 == 1)
    std::cout << "YES" << std::endl;
    else
    cout<<"NO"<<"\n";
        
    return  0;
}	