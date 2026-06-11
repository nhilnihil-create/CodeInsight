#include <bits/stdc++.h>

typedef long long ll;

using namespace std;


int main()
{
    string s;
    cin >> s;
    int score = 0;
    for(int i=0; i<s.length(); i++){
        if(i%2 && s[i] == 'g')
            score++;
        else if(i%2 == 0 && s[i] == 'p')
            score--;
    }
    cout << score << endl;
}
