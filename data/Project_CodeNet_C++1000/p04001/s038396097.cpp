#include <iostream>
#include <string>
using namespace std;

int main()
{
    string S;
    cin >> S;
    long sum = 0;
    for(long bits = 0; bits < (1 <<(S.size() - 1)); ++bits){
        long sum1 = 0;
        string tmp = S;
        long size = tmp.size();
        for(long i = 0; i < S.size() - 1; ++i){
            if(bits & (1<<i)){
                tmp.insert(size - 1 - i, "+");
            }
        }
      
        long sum2 = 0;
        for(long i = 0; i < tmp.size(); i++){
            if(!(tmp[i] == '+')){
                sum2 = sum2 * 10 + (tmp[i] - '0');
            }else{
                sum1 += sum2;
                sum2 = 0;
            }
        }
     
        sum += sum2;
        sum += sum1;
    }
    cout << sum << endl;
} 
//オーバーロードされた関数 "std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::insert [代入_CharT=char, _Traits=std::char_traits<char>, _Alloc=std::allocator<char>]" のインスタンスが引数リストと一致しません -- 引数の型: (long, char) -- オブジェクト型は std::string です