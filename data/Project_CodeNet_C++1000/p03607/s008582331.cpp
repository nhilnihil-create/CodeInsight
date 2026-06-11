#include <iostream>
#include <unordered_set>
#include <list>
#include <set>
using namespace std;
int main(){
    int N;
    cin >> N;
    unordered_set<int> m;
    int t;
    for(int i=0; i<N; i++){
        cin >> t;
        if(m.find(t) == m.end()){
            m.insert(t);
        } else {
            m.erase(t);
        }
    }
    cout << distance(m.begin(),m.end()) << endl;
    return 0;
}