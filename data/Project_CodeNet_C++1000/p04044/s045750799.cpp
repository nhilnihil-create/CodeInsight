#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, l;
    cin >> n >> l;
    vector<string> words;
    string word;
    for (int i = 0; i < n; i++){
        cin >>  word;
        words.push_back(word);
    }

    sort(words.begin(), words.end());
    string out = "";
    for (string w:words) out+= w;
    cout << out << endl;
    return 0;

}