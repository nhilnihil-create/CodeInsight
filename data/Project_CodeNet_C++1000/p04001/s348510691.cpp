#include <iostream>
#include <bitset>
using namespace std;

int main() {

    string S;

    cin >> S ;

    long ans = 0;

    // ビットの全組み合わせループ
    for (int tmp = 0; tmp < (1 << (S.size() - 1)); tmp++) {

        //ビット表現(0000)
        bitset<10> s(tmp);
        //cout << s << "  -------"<<endl;

        long sum = 0;
        string sum_str;
        for (long i = 0; i < S.size(); i++) {
            sum_str += S[i];
            //cout << sum_str << endl;
            if (s.test(i)) {
                //cout << "sum 1 ! " << sum_str << endl;
                sum += stoll(sum_str.c_str());
                sum_str = "";
            }
        }
        //cout << "sum 2 ! " << sum_str <<  endl;
        sum += stoll(sum_str.c_str());
        //cout << "sum: "<< sum << endl;

        ans += sum;

        //cout << "ans: " << ans << endl;
    }
    cout << ans << endl;

    return 0;

}