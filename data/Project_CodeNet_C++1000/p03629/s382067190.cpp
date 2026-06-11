#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

string ans;

void dfs(const vector< vector<int> > &next, const vector<int> &groups, int now, int need) {
    for(int j=0; j<26; j++) {
        if(next[j][now] == -1) {
            ans.push_back('a' + j);
            return;
        }
        if(groups[next[j][now] + 1] < need) {
            ans.push_back('a' + j);
            dfs(next, groups, next[j][now], need-1);
            return;
        }
    }
}

int main(void) {
    string A;
    cin >> A;
    A.insert(0, "_");
    int N = A.size();

    vector< vector<int> > next(26, vector<int>(N, -1));
    for(int i=N-1; i; i--) {
        for(int j=0; j<26; j++) {
            next[j][i-1] = next[j][i];
        }
        next[A[i]-'a'][i-1] = i;
    }

    set<char> st;
    vector<int> groups(N);
    for(int i=N-1; i; i--) {
        st.insert(A[i]);
        if(st.size() == 26) {
            groups[i] = 1;
            st.clear();
        }
    }
    for(int i=N-1; i; i--) {
        groups[i-1] += groups[i];
    }

    dfs(next, groups, 0, groups[0]);

    cout << ans << endl;
    return 0;
}
