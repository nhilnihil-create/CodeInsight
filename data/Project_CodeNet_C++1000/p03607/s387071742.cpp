#include<iostream>   //AA06( 15/ 07/ 20) If u see my code, Have a Good Day! (^_^)
#include<set>
#include<iterator>
#define JonSnow ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

using namespace std;

int main()
{
    JonSnow;

    int n, A;

    set <int> S;

    set <int> :: iterator I;

    cin >> n;

    while(n--) {

        cin >> A;

        I = S.find(A);

        if (I == S.end()) {

            S.insert(A);

        }

        else {

            S.erase(A);

        }

    }

    cout << S.size() << endl;

    return 0;
}
