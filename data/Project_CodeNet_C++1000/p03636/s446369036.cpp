#include<iostream>
#include<string>

using namespace std;

int main(){
   string s;

   cin >> s;
   cout << *(s.begin()) << s.size() - 2 << *(s.end() - 1) << endl;
}