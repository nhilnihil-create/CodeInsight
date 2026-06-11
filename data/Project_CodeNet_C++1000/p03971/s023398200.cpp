#include <bits/stdc++.h>

#define REPI(x) for(int i=0;i<x;i++)
#define REPJ(x) for(int j=0;j<x;j++)

using namespace std;

int main ()
{
    int N,A,B,fin,abroad;
    string S;

    cin >> N >> A >> B;
    cin >> S;

    fin = 0;
    abroad = 1;

    REPI(N)
    {
        if (S[i] == 'a'){
            if (fin < A+B)
            {
                fin++;
                cout << "Yes" << endl;
                continue;
            }                
        }else if (S[i] == 'b'){
            if (fin < A+B && abroad <= B){
                fin++;
                cout << "Yes" << endl;
                abroad++;
                continue;
            }
            abroad++;
        }
        cout << "No" << endl;
    }
    return 0;
}