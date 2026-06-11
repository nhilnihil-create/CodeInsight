#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    string s1,s2,s3;cin>>s1>>s2>>s3;
    char S1 = s1[0] - 'a' + 'A';
    char S2 = s2[0] - 'a' + 'A';
    char S3 = s3[0] - 'a' + 'A';
    printf("%c%c%c\n",S1, S2, S3);
    return 0;
}