#include<iostream>
#include<string>
using namespace std;
int main()
{
    int k = 0;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = i + 1; j < s.size(); j++)
            {
                if(s[i] == s[j])
                k++;
            }
    }
    if(k == 0)
        cout << "yes";
    else
        cout << "no";

    return 0;
}