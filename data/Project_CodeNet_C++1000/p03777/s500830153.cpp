#include<bits/stdc++.h>
using namespace std;
#define Yes(n) cout << ((n) ? "YES" : "NO") << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(V) (V).begin(),(V).end()
#define SORT(V) sort(ALL(V))

//vector<string> split(string,string);

//template<typename T>
//void swap(T*,T*);
//char ToUpper (char cX) { return toupper(cX); }

int main()
{
    string a,b;
    cin >> a >> b;
    if(a == "H")
    {
        if(b == "H")
            cout << "H";
        else
            cout << "D";
    }
    else
    {
        if(b == "H")
            cout << "D";
        else
            cout << "H";
    }
}