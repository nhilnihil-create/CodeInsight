#include <iostream>
#include <vector>
#include <cstring>



#define REP(i, n) for (long long i = 0; i < (n); i++) 
#define ll long long

using namespace std;

int main(){
    string S;
    cin >> S;

    REP(i,S.size())
    {
        if(i == 4)
        {
            cout << " ";
        }
        cout << S[i];
    }
    cout << endl;
    

}


