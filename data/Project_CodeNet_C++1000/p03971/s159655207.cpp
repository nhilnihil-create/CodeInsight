#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    int N, A, B;
    string S;
    int i = 0, e = 0, o = 0;
    cin >> N >> A >> B >> S;
    for (size_t j = 0; j < N; j++)
    {
        //cout << S.at(j);
        if (S.at(j) == 'a')
        {
            if(A + B > i + e)
            {
                i++;
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            
        }
        else if (S.at(j) == 'b')
        {
            if(B > e && A + B > i + e)
            {
                e++;
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
            
        }
        else
        {
            o++;
            cout << "No" << endl;
        }
        
        
    }
    

    return 0;
}