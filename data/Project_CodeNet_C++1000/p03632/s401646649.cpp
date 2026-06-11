 #include<bits/stdc++.h>
 using namespace std;

 int main(){
     int ab, ae, bb, be;
     cin >> ab >> ae >> bb >> be;
     int begin = max(ab, bb);
     int end = min(ae, be);
     cout << max(0, end - begin) << endl;
}