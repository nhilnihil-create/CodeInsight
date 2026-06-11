#include<iostream>
#include<cmath>
using namespace std;


int main()
{
    string s;
    char s_[50001] = {0};
    cin >> s;
    int j = 0;
    for (int i = 0; i < s.size(); i += 2)
    {
        s_[j++] = s[i];
    }
    cout << s_ << endl;
}