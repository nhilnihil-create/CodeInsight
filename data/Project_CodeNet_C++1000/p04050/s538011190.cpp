#include <bits/stdc++.h>

using namespace std;

const int M = 110;
vector <int> odd;
int A[M];
int n, m;

int main() {
     //freopen("a.txt", "r", stdin);
     cin >> n >> m;
     for(int i = 1; i <= m; ++i)
         cin >> A[i];
     if(m == 1) {
         cout << A[1] << endl;
         if(A[1] == 1) {
             cout << 1 << endl << 1 << endl;
             return 0;
         }
         cout << 2 << endl;
         cout << A[1] - 1 << " " << 1 << endl;
         return 0;
     }
     for(int i = 1; i <= m; ++i) {
         if(A[i] % 2 == 1)
             odd.push_back(i);
     }
     if(odd.size() > 2) {
         puts("Impossible");
         return 0;
     }
     if(odd.size() > 0) swap(A[odd[0]], A[1]);
     if(odd.size() > 1) swap(A[odd[1]], A[m]);

     for(int i = 1; i <= m; ++i)
         cout << A[i] << " ";
     cout << endl;
     A[1]++; A[m]--;
     if(A[m] == 0) m--;
     cout << m << endl;
     for(int i = 1; i <= m; ++i) {
         cout << A[i] << " ";
     }

}