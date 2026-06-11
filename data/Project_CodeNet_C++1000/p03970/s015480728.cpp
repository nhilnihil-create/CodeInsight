#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
     string S;
     string source = "CODEFESTIVAL2016";

     cin >> S;

     int count = 0;

     for (int i = 0; i < source.length(); i++) {
	  if (S.at(i) != source.at(i)) {
	       count++;
	  }
     }

     cout << count << endl;
     
     return 0;
}
