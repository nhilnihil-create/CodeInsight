#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int vector_finder(std::vector<int> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int main()
{
    int aa,a,b,c,i=0,m;
    vector<int> box(110); //1<=A<=100より、余りは99通り
    cin >> aa >> b >> c;

    while (true)
    {
        i++;
        a = aa*i;
        m = a%b;
        if(m==c) {
            cout <<"YES"<< endl;
            return 0;
        }
        if(vector_finder(box,m)==1) {
            cout << "NO" << endl;
            return 0;
        }
        box.push_back(m);
    }
    return 0;
}