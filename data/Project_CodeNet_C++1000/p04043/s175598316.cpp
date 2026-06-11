#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;


typedef long long int ll;
typedef unsigned long long  ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef deque <int> di;
typedef deque <char> dc;
typedef vector<long long int> vll;

#define f(i, a, b) for (int i = a; i < b; i++)
#define f2(i, a, b) for (int i = a; i <=b; i++)
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front;
int main() {

int a;
int b;
int c;
cin >> a >> b >> c;
int d = a + b + c;

if (d != 17) {
    cout << "NO";
}
else {
    if (a != 5 && a != 7) {
        cout << "NO";
    }
    else if (b!=5 && b!= 7) {
        cout << "NO";
    }
    else if (c!=5 && c!=7) {

        cout << "NO";
    }
    else {
        cout << "YES";
    }
}
return 0;
}
