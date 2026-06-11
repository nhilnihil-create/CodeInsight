#include<bits/stdc++.h>
using namespace std;
#define MAX_SIZE 100 // Maximum string size

int main()
{
    char str[MAX_SIZE];
    int i, len, status;
    int freq[26];

    cin >> str;

    len = strlen(str);

    /* Initialize frequency of each character to 0 */
    for(i=0; i<26; i++)
    {
        freq[i] = 0;
    }


    /* Find total number of occurrences of each character */
    for(i=0; i<len; i++)
    {
        /* If the current character is lowercase alphabet */
        if(str[i]>='a' && str[i]<='z')
        {
            freq[str[i] - 97]++;
        }
        else if(str[i]>='A' && str[i]<='Z')
        {
            freq[str[i] - 65]++;
        }
    }

    for(i=0; i<26; i++)
    {
        /* If current character exists in given string */
        if(freq[i]%2 == 0)
        {
            status = 1;
        }
        else{
            status = -1;
            break;
        }
    }
    if(status == -1)
        cout << "No";
    else if(status == 1)
        cout << "Yes";

    return 0;
}
