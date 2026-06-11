#include<iostream>
#include<string>
#include<map>

using namespace std;

int main(){
    string s;
    map<char, int> D;
    int N, my_p, score;
    cin >> s;
    N = s.length();
    for (int i=0; i<N; i++){
        if (D.find(s[i]) != D.end()){
            D[s[i]]++;
        }else{
            D[s[i]] = 1;
        }
    }
    my_p = N/2;
    score = my_p - D['p'];
    cout << score << endl;
    return 0;
}