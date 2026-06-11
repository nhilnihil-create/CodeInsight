#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b ;
    int i, l ;
    cin >> a ;
    b = a ;
    l = b.size() ;
    for(i=0;i<l/2;i++)
        swap(b[i],b[l-i-1]) ;
    for(i=0;i<l;i++)
    {
        if(b[i]=='b')
            b[i] = 'd' ;
        else
        {
            if(b[i]=='d')
                b[i] = 'b' ;
            else
            {
                if(b[i]=='p')
                    b[i] = 'q' ;
                else
                    b[i] = 'p' ;    
            }    
        }                
    }
    if(a==b)
        cout << "Yes" << endl ;
    else
        cout << "No" << endl ;
    //system("PAUSE");
    return 0 ;
}
