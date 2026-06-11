#include <bits/stdc++.h>
using namespace std;
int main(void){
    int a,len,i=0,c=0;
    string s,n,d,f,g,h;
    cin >> s;
    reverse(s.begin(), s.end());
    n="maerd";
    d="remaerd";
    f="esare";
    g="resare";
    len=s.size();

    while(len>i)
    {
        if(s.substr(i,5)==n)
        {
             h=h+n;
             i+=5;
        }
        else if(s.substr(i,7)==d)
            {
                h=h+d;
                i+=7;
                
            }
        else if(s.substr(i,5)==f)
            {
                h=h+f;
                i+=5;
            
            }

            else if(s.substr(i,6)==g)
            {
                h=h+g;
                i+=6;
            }
            else
            {
                break;
            }
    }
    if(s==h)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    
    
    /*len=s.size();
    int c=0;
    if(len<5)
    {
        cout << "NO" << endl;
        return 0;
    }
        if(s.substr(i,8)=="dreamera")
        {
             n=n+d;
             i+=5;
            c++;
        }
            if(s.substr(i,6)==h && c==0)
            {
                n=n+h;
                i+=6;
                c++;
            }
        else if(s.substr(i,7)==f && c==0)
            {
                n=n+f;
                i+=7;
            c++;
            }

            else if(s.substr(i,5)==g && c==0)
            {
                n=n+g;
                i+=5;
            }
        
    while(i<=len)
    {
        if(s.substr(i,8)=="dreamera")
        {
             n=n+d;
             i+=6;
        }
        if(s.substr(i,6)==h)
            {
                n=n+h;
                i+=7;
            }
        if(s.substr(i,7)==f)
            {
                n=n+f;
                i+=8;
            }

            if(s.substr(i,5)==g)
            {
                n=n+g;
                i+=6;
            }
            if(s.substr(len-5,5)==d)
            {
                n=n+d;
                i+=6;
            }
    }
    if(s==n)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << n << endl;
    }*/     


    return 0;

}
