#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <regex>
using namespace std;

template<class T, class Compare = greater<T> >
using MinHeap = priority_queue<T, vector<T>, Compare>;
template<class T, class Compare = less<T> >
using MaxHeap = priority_queue<T, vector<T>, Compare>;
using llong = long long;

string s;
smatch sm;
regex pattern("YAKI.*");

int main() {

    cin >> s;
    if (regex_match(s, sm, pattern)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
