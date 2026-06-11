#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std ;

int main(){
    std::ios_base::sync_with_stdio(0);  cin.tie(NULL);  cout.tie(NULL);
    int N, L ;
    cin >> N >> L ;
    vector<string> words(N) ;
    for (int i = 0; i < N && cin >> words[i]; i++);
    sort(words.begin(), words.end());
    for (int i = 0; i < N && cout << words[i]; i++) ;
    return 0 ;
}