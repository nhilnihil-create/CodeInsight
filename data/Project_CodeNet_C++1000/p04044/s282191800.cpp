#include<iostream>
#include<string>
#include<list>
using namespace std;

int main(){
    int N, L;
    string input;
    list<string> ls;
    list<string>::iterator itr;
    
    cin >> N >> L;
    for (int i=0; i<N; i++){
        cin >> input;
        ls.push_back(input);
    }
    ls.sort();
    for (itr=ls.begin(); itr!=ls.end(); itr++){
        cout << *itr;
    }
    return 0;
}