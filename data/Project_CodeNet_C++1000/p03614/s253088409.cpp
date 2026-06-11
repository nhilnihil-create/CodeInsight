#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int N; cin >> N;
    stack<int> st;

    int p;
    for(int i=1;i<=N;i++){
        cin >> p;
        if(p == i){
            if(st.empty()) st.push(i);
            else if(st.top() == i-1) continue;
            else if(st.top() != i-1) st.push(i);
        }
    }

    cout << st.size() << endl;
    return 0;
    
}