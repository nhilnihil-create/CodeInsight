#include <bits/stdc++.h>
using namespace std;

int main(){
    string A;
    cin >> A;
    A = "!" + A;
    int N = A.size();
    set<char> st;
    int num = 1;
    vector<vector<int>> nxt(N, vector<int>(26, N));
    vector<int> now(26, N);
    vector<int> len(N+2);
    len[N] = 1;
    for(int i=N-1; i>=0; i--){
        st.insert(A[i]);
        if(st.size() == 26){
            num++;
            st.clear();
        }
        len[i] = num;
        for(int c=0; c<26; c++) nxt[i][c] = now[c];
        if(i) now[A[i]-'a'] = i;
    }
    int L = len[1];
    int pt = 0;
    string ans;
    while(pt < N){
        for(char i=0; i<26; i++) if(ans.size() + 1 + len[nxt[pt][i] + 1] == L){
            ans.push_back('a'+i);
            pt = nxt[pt][i];
            break;
        }
    }
    cout << ans << endl;
}
