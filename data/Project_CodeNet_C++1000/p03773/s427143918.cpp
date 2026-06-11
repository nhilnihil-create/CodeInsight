#include <bits/stdc++.h>
using namespace std;

int main()
{

        int A, B;

        cin >> A >> B;
        int time = A + B;
        if (time > 23) {
                time -= 24;
        }
        cout << time << endl;


}
