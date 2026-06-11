#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, a, b;
    string s;
    cin >> n >> a >> b >> s;

    map<char, int> rank;
    int pass = 0;

    for (int i=0; i<n; i++){
        char temp;
        temp = s.at(i);
        rank[temp]++;

        if ((temp == 'a') && (pass < a+b)){
            cout << "Yes" << endl;
            pass++;
        }
        else if ((temp == 'b') && (pass < a+b) && (rank[temp] <= b)){
            cout << "Yes" << endl;
            pass++;
        }
        else cout << "No" << endl;
    }

    cout << endl;
    return 0;
}