#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, f = "First", sc = "Second";
    cin >> s;
    int len = s.size();
    if( (len - 2) % 2 ) {
        if(s[0] != s[len-1])
            cout << f;
        else
            cout << sc;
    }
    else {
        if(s[0] != s[len-1])
            cout << sc;
        else
            cout << f;
    }
}
/*
From the conclusion, the exclusive OR of "the length of s is even" and "the first and last characters of s are the same"
If true, the second player wins, and if false, the first player wins. This is shown below.
Consider the final s when either player becomes inoperable. The final s is
Two different characters should alternate, such as “abababab ...”. Because the same character from the rule
If there is no place where is adjacent, and if there is a place where three different characters are consecutive, such as “abc”, the middle character is still taken.
Because it can be removed.
The final length of s is not uniquely determined, but its evenness is uniquely determined. Specifically, with the first character of s
If the last character is the same, it will be an odd length like “ababa”, and if the first and last characters of s are different, it will be “ababab”.
It has an even length as shown in. From the above, since the evenness of the length of s is known at the beginning and the end, the evenness of the number of turns is also known.
I understand. Therefore, it is possible to find out which player will not be able to operate first.
*/