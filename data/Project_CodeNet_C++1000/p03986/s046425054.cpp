#include <iostream>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int size = s.size();
    int sum = 0;
    for (int i = 0; i < s.size(); i++) 
	{
        if (s[i] == 'S') 
		{
            sum++;
        }
        if (s[i] == 'T') 
		{
            if (sum > 0) 
			{
                sum--;
                size -= 2;
            }
        }
    }
    cout << size << endl;
    return 0;
}

