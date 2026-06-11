#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int N = s.size();
    string answer;
    for (int i = 0; i < N; ++i)
    {
        if (i % 2 == 0){
            answer += s[i];
        }
    }
    cout << answer << endl;
}