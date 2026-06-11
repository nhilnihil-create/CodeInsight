#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void a_three_letter_acronym(void) {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;

	char diff = 'A' - 'a';

	printf("%c%c%c\n", s1[0] + diff, s2[0] + diff, s3[0] + diff);
}

int main()
{
    a_three_letter_acronym();
    return 0;
}