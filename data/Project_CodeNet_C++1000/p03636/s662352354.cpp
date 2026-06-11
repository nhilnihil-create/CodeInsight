#include <iostream>
#include<string>
using namespace std;

int main(){
string word;
cin >>word;
size_t size = word.length();
int middle = size - 2;
int last = size - 1;
cout<<word[0]<<middle<<word[last]<<endl;
}