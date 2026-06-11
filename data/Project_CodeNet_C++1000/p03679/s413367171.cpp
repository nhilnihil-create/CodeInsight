#include<bits/stdc++.h>
using namespace std;
#define Yes(n) cout << ((n) ? "YES" : "NO") << endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(V) (V).begin(),(V).end()
#define SORT(V) sort(ALL(V))

vector<string> split(string,string);

//template<typename T>
//void swap(T*,T*);
//char ToUpper (char cX) { return toupper(cX); }

int main()
{
    int X,A,B;
    cin >> X >> A >> B;
    if(A >= B)
    {
        cout << "delicious";
    }
    else if(X - (B - A) >= 0)
    {
        cout << "safe";
    }else
    {
        cout << "dangerous";
    }
}
