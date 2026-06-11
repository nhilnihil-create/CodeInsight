#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  cout <<(char) (((int) s1[0]) - 32) << (char) (((int) s2[0]) - 32) <<(char) (((int) s3[0]) - 32);
  return 0;
}