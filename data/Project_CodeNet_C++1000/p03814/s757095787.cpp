#include <bits/stdc++.h>
using namespace std;

bool is_square(int n)
{
    for (int i = 0; i <= n; i++)
    {
        if (i * i == n)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    string s;
    cin>>s;
    int first_a_index=-1;
    int last_z_index=-1;
    for (size_t i = 0; i < s.length(); i++)
    {
        if(s[i]=='A'&&first_a_index==-1){
            first_a_index = i;
        }
        if(s[i]=='Z'){
            last_z_index = i;
        }
    }
    cout << last_z_index - first_a_index + 1 << endl;

    return 0;
}