#include<iostream>
#include<string>
#include<map>

using namespace std;

string str;
map<char, int> record;

int main() {
    cin >> str;
    for(auto s : str) {
        record[s]++;
    }
    for (map<char, int>::iterator it = record.begin(); it != record.end(); it++) {
        if((*it).second % 2 != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}