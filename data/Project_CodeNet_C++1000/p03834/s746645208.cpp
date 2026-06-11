#include<iostream>
#include<math.h>
#include<string>
#include<iomanip>
#include <limits>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int main()
{
std::string s; std::getline(cin,s);
std::replace(s.begin(), s.end(),',', ' ');
cout<<s;
}
