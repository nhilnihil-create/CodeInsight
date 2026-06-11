#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n , a , b ; cin >> n >> a >> b ;
    string str ; cin >> str ;
    int total = a+b;
    for(int i = 0 ; i < str.length();i++)   
    {
        if(str[i]=='c') cout << "No" << endl;
        if(str[i]=='a')
        {
            if(total>0) 
            {
                cout <<"Yes" << endl;
                total--;
            }
            else cout << "No" << endl;
        }
        if(str[i]=='b') 
        {
            if(total>0)
            {
                if(b>0)
                {
                    cout <<"Yes" << endl;
                    total--;
                    b--;
                }
                else
                {
                    cout << "No" << endl;
                }
            }
            else cout << "No" << endl;
        }
    }
    return 0 ;
}