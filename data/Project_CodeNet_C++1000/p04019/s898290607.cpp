#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main(int argc, char** argv) {
    string ch;
    cin>>ch;
    if (ch.length()==1)
        cout<<"No";
else{
    bool n=false;
    bool s=false;
    bool e=false;
    bool w=false;

    bool r=false;


    int i=0;
    while ((i<ch.length()) )
    {
        switch (ch[i]){

            case 'N':
                n=true;
                break;
            case 'S':
                s=true;
                break;
            case 'E':
                e=true;
                break;
            case 'W':
                w=true;
                break;
        }

        if (n==true)
            if (s== true)
                if (e== true)
                    if (w== true)
                        r=true;
                    else r=false;
                else
                if (w== true)
                    r=false;
                else r=true;
            else r=false;
        else
        if (s== true) r=false;
        else
            if (e== true)
            if (w== true)
                r=true;
            else r=false;
        else
        if (w== true)
            r=false;
        else r=true;
        i++;
    }

    if (r==true)
        cout<<"Yes";
    else
        cout<<"No";
}
    return 0;
}