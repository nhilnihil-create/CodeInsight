#define _GLIBCXX_DEBUG // 配列エラー
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
// typedef pair<int,int> pp;
const int INF = 1e9;
const int MOD = 1000000007;

int64_t H, W, N; // N = min((unsigned int)100000, H*W);
map<unsigned int, map<unsigned int, int>>box;
vector<int64_t>cnt(10, 0);

void printAnswer(vector<int64_t> &v);

void incDec(int decNum);
void changeCnt(unsigned int hPos, unsigned int wPos);
void check(unsigned int hPos, unsigned int wPos);

int main() {
  cin >> H >> W >> N;

  cnt.at(0) = (H - 2)*(W - 2);

  for(unsigned int i = 0; i < N; i++) {
    unsigned int hPos, wPos;
    cin >> hPos >> wPos;

    check(hPos, wPos);
  }
  printAnswer(cnt);
}


void printAnswer(vector<int64_t> &v) {
  for(int i = 0; i < (int)v.size(); i++) {
    cout << v.at(i) << endl;
  }
}

void incDec(int decNum) {
  cnt.at(decNum) -= 1;
  cnt.at(decNum+1) += 1;
}

void changeCnt(unsigned int hP, unsigned int wP) {
  if(!(box.count(hP) > 0)) {
    box[hP][wP] = 1;
    incDec(0);
  } else {
    if(box.at(hP).count(wP) > 0) {
      incDec( box.at(hP).at(wP)); // 現在のやつのカウント変更
      box.at(hP).at(wP)++;
    } else {
      box.at(hP).emplace(wP, 1);
      incDec(0);
    }
  }
}

void check(unsigned int hPos, unsigned int wPos) {
  for(int i = -1; i <= 1; i++) { // 上下左右
    for(int j = -1; j <= 1; j++) {
      if(hPos+i < 2 || hPos+i > H-1) {break;}
      if(wPos+j < 2 || wPos+j > W-1) {continue;}
      changeCnt(hPos+i, wPos+j);
    }
  }
}
