#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;

    vector<bool> rate(8,false);
    int other=0;
    rep(i,n) {
        int ibuff;
        cin >> ibuff;
        if (ibuff<=399)         rate.at(0)=true;
        else if (ibuff<=799)    rate.at(1)=true;
        else if (ibuff<=1199)   rate.at(2)=true;
        else if (ibuff<=1599)   rate.at(3)=true;
        else if (ibuff<=1999)   rate.at(4)=true;
        else if (ibuff<=2399)   rate.at(5)=true;
        else if (ibuff<=2799)   rate.at(6)=true;
        else if (ibuff<=3199)   rate.at(7)=true;
        else                    other++;
    }

    int trueCnt=0;
    int minValue=0, maxValue=0;
    //trueの数を数える
    trueCnt = count(rate.begin(), rate.end(), true);

    //最小値は現在使用している色の数(最小1)
    minValue = max(1, trueCnt);

    //最大値は自由色を最大限ちりばめる
    maxValue = trueCnt+other;

    cout << minValue << " " << maxValue << endl;

    return 0;
}