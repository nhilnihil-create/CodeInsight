#include <bits/stdc++.h>
using namespace std;
int main(){
  string w;
  cin >> w;
  int A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, G = 0, H = 0, I = 0, J = 0, K = 0, L = 0, M = 0, N = 0, O = 0, P = 0, Q = 0, R = 0, S = 0, T = 0, U = 0, V = 0, W = 0, X = 0, Y = 0, Z = 0, x = w.size();
  for (int i = 0; i < x; i++) {
    if (w.at(i) == 'a') {A++;}
    else if (w.at(i) == 'b') {B++;}
    else if (w.at(i) == 'c') {C++;}
    else if (w.at(i) == 'd') {D++;}
    else if (w.at(i) == 'e') {E++;}
    else if (w.at(i) == 'f') {F++;}
    else if (w.at(i) == 'g') {G++;}
    else if (w.at(i) == 'h') {H++;}
    else if (w.at(i) == 'i') {I++;}
    else if (w.at(i) == 'j') {J++;}
    else if (w.at(i) == 'k') {K++;}
    else if (w.at(i) == 'l') {L++;}
    else if (w.at(i) == 'm') {M++;}
    else if (w.at(i) == 'n') {N++;}
    else if (w.at(i) == 'o') {O++;}
    else if (w.at(i) == 'p') {P++;}
    else if (w.at(i) == 'q') {Q++;}
    else if (w.at(i) == 'r') {R++;}
    else if (w.at(i) == 's') {S++;}
    else if (w.at(i) == 't') {T++;}
    else if (w.at(i) == 'u') {U++;}
    else if (w.at(i) == 'v') {V++;}
    else if (w.at(i) == 'w') {W++;}
    else if (w.at(i) == 'x') {X++;}
    else if (w.at(i) == 'Y') {Y++;}
    else {Z++;}
  }
  if (A % 2 == 0 && B % 2 == 0 && C % 2 == 0 && D % 2 == 0 && E % 2 == 0 && F % 2 == 0 && G % 2 == 0 && H % 2 == 0 && I % 2 == 0 && J % 2 == 0 && K % 2 == 0 && L % 2 == 0 && M % 2 == 0 && N % 2 == 0 && O % 2 == 0 && P % 2 == 0 && Q % 2 == 0 && R % 2 == 0 && S % 2 == 0 && T % 2 == 0 && U % 2 == 0 && V % 2 == 0 && W % 2 == 0 && X % 2 == 0 && Y % 2 == 0 && Z % 2 == 0) {
    cout << "Yes" << endl;
  }
  else {cout << "No" << endl;}
}