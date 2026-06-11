#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,b=0,i=0,j,c=0,s=100000;
    string w;
    cin >> w;
    n=w.size();
    for(char c='a';c<='z';c++)
    {
       for(i=0;i<n;i++)
       {
            if(w[i]==c)
            {
                b++;
            } 
        }
        if(b%2!=0)
        {
            cout << "No" << endl;
            return 0;
        }
        b=0;
    }
    cout << "Yes" << endl;

    return 0;

}
