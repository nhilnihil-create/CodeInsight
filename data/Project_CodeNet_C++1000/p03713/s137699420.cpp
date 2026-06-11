#include<iostream>
#include<vector>
#include <algorithm>

#define ll long long

using namespace std;

int main(){
    ll h, w,_s, s, l1;
    vector<int> ans;
     
    cin >> h >> w;

    if(h % 3 == 0 || w % 3 == 0){
        cout << 0 << endl;
    }else{
        _s = h * w;
        s = _s / 3;

        l1 = s / w;
        vector<ll> vw1(3);
        vector<ll>::iterator ite1;
        vector<ll>::iterator ite2;
        vw1.at(0) = l1*w;
        if(w % 2 == 0 || (h - l1) % 2 == 0){
            ans.push_back(abs(vw1.at(0) - (_s - vw1.at(0)) / 2));
        }else{
            if(w > (h - l1)){
                vw1.at(1) = ((_s - vw1.at(0)) + (h - l1)) / 2;
                vw1.at(2) = ((_s - vw1.at(0)) - (h - l1)) / 2;
                ite1 = max_element(vw1.begin(), vw1.end());
                ite2 = min_element(vw1.begin(), vw1.end());
                ans.push_back(*ite1 - *ite2);
            }else{
                vw1.at(1) = ((_s - vw1.at(0)) + w) / 2;
                vw1.at(2) = ((_s - vw1.at(0)) - w) / 2;
                ite1 = max_element(vw1.begin(), vw1.end());
                ite2 = min_element(vw1.begin(), vw1.end());
                ans.push_back(*ite1 - *ite2);
            }
        }



        l1 = (s + w - 1) / w;
        vw1.at(0) = l1*w;
        if(w % 2 == 0 || (h - l1) % 2 == 0){
            ans.push_back(abs(vw1.at(0) - (_s - vw1.at(0)) / 2));
        }else{
            if(w > (h - l1)){
                vw1.at(1) = ((_s - vw1.at(0)) + (h - l1)) / 2;
                vw1.at(2) = ((_s - vw1.at(0)) - (h - l1)) / 2;
                ite1 = max_element(vw1.begin(), vw1.end());
                ite2 = min_element(vw1.begin(), vw1.end());
                ans.push_back(*ite1 - *ite2);
            }else{
                vw1.at(1) = ((_s - vw1.at(0)) + w) / 2;
                vw1.at(2) = ((_s - vw1.at(0)) - w) / 2;
                ite1 = max_element(vw1.begin(), vw1.end());
                ite2 = min_element(vw1.begin(), vw1.end());
                ans.push_back(*ite1 - *ite2);
            }
        }


        l1 = s / h;
        vw1.at(0) = l1*h;
        if(h % 2 == 0 || (w - l1) % 2 == 0){
            ans.push_back(abs(vw1.at(0) - (_s - vw1.at(0)) / 2));
        }else{
            if(h > (w - l1)){
                vw1.at(1) = ((_s - vw1.at(0)) + (w - l1)) / 2;
                vw1.at(2) = ((_s - vw1.at(0)) - (w - l1)) / 2;
                ite1 = max_element(vw1.begin(), vw1.end());
                ite2 = min_element(vw1.begin(), vw1.end());
                ans.push_back(*ite1 - *ite2);
            }else{
                vw1.at(1) = ((_s - vw1.at(0)) + h) / 2;
                vw1.at(2) = ((_s - vw1.at(0)) - h) / 2;
                ite1 = max_element(vw1.begin(), vw1.end());
                ite2 = min_element(vw1.begin(), vw1.end());
                ans.push_back(*ite1 - *ite2);
            }
        }


        l1 = (s + h - 1) / h;
        vw1.at(0) = l1*h;
        if(h % 2 == 0 || (w - l1) % 2 == 0){
            ans.push_back(abs(vw1.at(0) - (_s - vw1.at(0)) / 2));
        }else{
            if(h > (w - l1)){
                vw1.at(1) = ((_s - vw1.at(0)) + (w - l1)) / 2;
                vw1.at(2) = ((_s - vw1.at(0)) - (w - l1)) / 2;
                ite1 = max_element(vw1.begin(), vw1.end());
                ite2 = min_element(vw1.begin(), vw1.end());
                ans.push_back(*ite1 - *ite2);
            }else{
                vw1.at(1) = ((_s - vw1.at(0)) + h) / 2;
                vw1.at(2) = ((_s - vw1.at(0)) - h) / 2;
                ite1 = max_element(vw1.begin(), vw1.end());
                ite2 = min_element(vw1.begin(), vw1.end());
                ans.push_back(*ite1 - *ite2);
            }
        }

        vector<int>::iterator ita = min_element(ans.begin(), ans.end());
        cout << *ita << endl;
    }
}