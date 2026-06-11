#include <iostream>
#include <string>
using namespace std;

char check_s(string s, int num) {
    char ans{};
    if (s[num] == 'a') {
        ans = 'a';
    } else if (s[num] == 'b') {
        ans = 'b';
    } else if (s[num] == 'c') {
        ans = 'c';
    }
    return ans;
}

int main() {
    string sa, sb, sc;
    cin >> sa >> sb >> sc;
    int i{0};
    int j{0};
    int k{0};

    char lead;
    lead = sa[0];
    i++;
    while ((sa.length() != i && lead == 'a') ||
           (sb.length() != j && lead == 'b') ||
           (sc.length() != k && lead == 'c')) {
        if (lead == 'a') {
            lead = check_s(sa, i);
            i++;
        } else if (lead == 'b') {
            lead = check_s(sb, j);
            j++;
        } else if (lead == 'c') {
            lead = check_s(sc, k);
            k++;
        }
    }
    switch (lead) {
        case 'a':
            cout << 'A' << endl;
            break;
        case 'b':
            cout << 'B' << endl;
            break;
        case 'c':
            cout << 'C' << endl;
            break;
    }

    return 0;
}
