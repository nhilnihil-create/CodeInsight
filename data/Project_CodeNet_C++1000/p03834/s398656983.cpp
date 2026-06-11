#include <bits/stdc++.h>
using namespace std;
int main()
{
    string x;
    cin >> x;
    for(int i = 0 ; i <x.size(); i++){
        if(x[i] == ','){
            x[i] = ' ';
        }
        cout << x[i];

    }
    cout << endl;
	return 0;
}
