#include <bits/stdc++.h>

using namespace std;

template<typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T> p) {
    out << "(" << p.first << "," << p.second << ")";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    for (auto a: v)
        out << a << " ";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const set<T>& S) {
    for (auto a: S)
        cout << a << " ";
    return out;
}

template<typename T>
ostream& operator<<(ostream& out, const multiset<T>& S) {
    for (auto a: S)
        cout << a << " ";
    return out;
}

template<typename S, typename T>
ostream& operator<<(ostream& out, const map<S, T>& M) {
    for (auto m: M)
        cout << "(" << m.first << "->" << m.second << ") ";
    return out;
}

template<typename S, typename T>
pair<S, T> operator+(pair<S, T> a, pair<S, T> b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

template<typename S, typename T>
pair<S, T> operator-(pair<S, T> a, pair<S, T> b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

struct KMP {
    string P;
    vector<int> F;

    void init(const string& P) {
        this->P = P;
        if (P.empty()) {
            F.assign(1, 0);
            return;
        }
        int m = P.size();
        F.resize(m + 1);
        F[0] = F[1] = 0;
        for (int i = 1; i < m; i++) {
            int j = F[i];
            while (j && P[j] != P[i])
                j = F[j];
            if (P[j] == P[i])
                j++;
            F[i+1] = j;
        }
        // cout << "P: " << P << endl;
        // cout << "F: " << F << endl;
    }

    int match(const string& T) {
        int n = T.size();
        int m = P.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j && P[j] != T[i])
                j = F[j];
            if (P[j] == T[i])
                j++;
            if (j == m)
                return i;
        }
        return -1;
    }

    vector<int> partial_match(const string& T) {
        int n = T.size();
        int m = P.size();
        int j = 0;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (j && P[j] != T[i])
                j = F[j];
            if (P[j] == T[i])
                j++;
            ans[i] = j;
        }
        return ans;
    }

    int last_partial_match(const string& T) {
        int n = T.size();
        int m = P.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j && P[j] != T[i])
                j = F[j];
            if (P[j] == T[i])
                j++;
        }
        return j;
    }

    vector<int> match_all(const string& T) {
        int n = T.size();
        int m = P.size();
        int j = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            while (j && P[j] != T[i])
                j = F[j];
            if (P[j] == T[i])
                j++;
            if (j == m)
                ans.push_back(i);
        }
        return ans;
    }

    int period() {
        int m = P.size();
        int match = F[m];
        if (match && m % (m - match) == 0)
            return m - match;
        return m;
    }
};

KMP kmp;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    string str1, str2;
    cin >> n >> str1 >> str2;
    kmp.init(str2);
    int m = kmp.last_partial_match(str1);
    cout << n + n - m << endl;
    return 0;
}
