#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    string Sa, Sb, Sc;
    cin >> Sa >> Sb >> Sc;

    vector<string> S = {Sa, Sb, Sc};
    vector<int> pt(3, 0);
    vector<int> len = {(int) S[0].size(), (int) S[1].size(), (int) S[2].size()};


    int turn = 0;

    while (true)
    {

        char val = S[turn][pt[turn]];

        pt[turn]++;

        if(val == 'a'){
            turn = 0;
        } else if(val == 'b'){
            turn = 1;
        } else {
            turn = 2;
        }

        bool st = true;
        for (int i = 0; i < 3; i++)
        {
            st &= (pt[i] <= len[i]);
        }
        if(!st) break;
    }

    for (int i = 0; i < 3; i++)
    {
        if(pt[i] > len[i]){
            if(i == 0){
                cout << 'A' << endl;
            } else if(i == 1){
                cout << 'B' << endl;
            } else {
                cout << 'C' << endl;
            }
        }
    }

    return 0;
}
