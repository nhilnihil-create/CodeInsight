#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)

int main()
{
    int N;
    cin >> N;
    
    vector<int> a(N);
    REP(i, N) {
        cin >> a[i];
    }
    
    //昇順にソート
    sort(a.begin(), a.end());
  
    if (a[0] == a[N-1]) { //a_iが全て等しい場合
        if (a[0] <= N / 2 || a[0] + 1 == N) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else if (a[0] + 1 == a[N-1]) { //a_iが二種類で差が1の場合
        /*
          このとき全体の種類数はa[N-1](大きい方)となる
          小さい方は自分の色を除くと種類数が減り、大きい方は自分の色を除いても種類数が減らない
          つまり小さい方は他の帽子の色と被ってはいけない
          逆に大きい方は少なくとも1つ同じ色の帽子がなければいけない
         */
      
        //小さい方と大きい方がそれぞれいくつあるかを求める
        int smallCount = 0;
        int bigCount = 0;
        for (int i=1; i<N; i++) {
            if (a[i] != a[i-1]) {
                smallCount = i;
                bigCount = N - i;
            }
        }
        
        if (bigCount == 1) {
            cout << "No" << endl;
        } else if (smallCount < a[N-1] && smallCount + (bigCount / 2) >= a[N-1]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}