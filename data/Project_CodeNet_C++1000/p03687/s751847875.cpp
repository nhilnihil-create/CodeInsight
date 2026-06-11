#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    string s;

    cin >> s;

    vector<int> chCount(26, 0);
    int maxCount = 0;


    for(int i = s.size() - 1; i >= 0; --i) {
        chCount[s[i] - 'a']++;
    }
    string tempS = s;
    int answer = 999999999;
    for(int i = 0; i < 26; ++i) {

        if(chCount[i] == 0)
            continue;
        char ch = 'a' + i;

        int count = 0;
        s = tempS;
        while(1) {

            int index;
            for(index = 0; index < s.size() && s[index] == ch; ++index);

            if(index == s.size())
                break;

            string temp = "";
            for(int i = 0; i < s.size() - 1; ++i) {

                if(s[i] == ch || s[i + 1] == ch)
                    temp += ch;
                else
                    temp += s[i];

            }

            s = temp;

            count++;
        }

        answer = min(answer, count);

    }

    cout << answer << endl;

    return 0;
}