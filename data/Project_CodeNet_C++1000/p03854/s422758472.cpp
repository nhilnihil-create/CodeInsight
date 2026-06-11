#include <iostream>
using namespace std;

int main() {

    string S;

    string S_tmp_5 = ""; //dream, erase
    string S_tmp_6 = ""; //eraser
    string S_tmp_7 = ""; //dreamer

    cin >> S;

    do {
        //cout << "do S: " << S << endl;

        if (S.size() == 5 || S.size() == 6|| S.size() == 7){
            if(S == "dream" || S == "erase" || S == "eraser" || S == "dreamer"){

                cout << "YES" << endl;
                return 0;

            }else{

                cout << "NO" << endl;
                return 0;
            }

        }

        S_tmp_5 = S.substr(S.size() - 5, 5);
        S_tmp_6 = S.substr(S.size() - 6, 6);
        S_tmp_7 = S.substr(S.size() - 7, 7);

        // cout << "S_tmp_5: " << S_tmp_5 << endl;
        // cout << "S_tmp_6: " << S_tmp_6 << endl;
        // cout << "S_tmp_7: " << S_tmp_7 << endl;


        if (S_tmp_5 == "dream" || S_tmp_5 == "erase"){
            S = S.substr(0, S.size() - 5);

            //cout << "5: new S: " << S << endl;

            if(S.size() == 0){
                cout << "YES" << endl;
                return 0;
            }
        }
        else if (S_tmp_6 == "eraser" ){
            S = S.substr(0, S.size() - 6);

            //cout << "6: new S: " << S << endl;

            if(S.size() == 0){
                cout << "YES" << endl;
                return 0;
            }
        }
        else if (S_tmp_7 == "dreamer" ){
            S = S.substr(0, S.size() - 7);

            //cout << "7: new S: " << S << endl;

            if(S.size() == 0){
                cout << "YES" << endl;
                return 0;
            }
        }
        else{
            cout << "NO" << endl;
            return 0;
        }


    }while (true);
    
    return 0;

}