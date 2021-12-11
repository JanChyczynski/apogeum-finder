#include <bits/stdc++.h>
using namespace std;
int maks=0;
int ile_danych(int v,int g){
    for (int t=0;t<1000;t++){
        int h = v*t-g*t*t/2;
        maks=max(maks,h);
        if (h<0){
            return t;
        }
    }
    cout << "o kurwa";
    return -1;
}


int main(){
    int v, g;//przyspieszenie, tlumienie
    cin >> v>>g;
    cout << ile_danych(v,g)<<" ";
    cout << maks<<endl;
    for (int t=0;t<1000;t++){
        int h = v*t-g*t*t/2;
        if (h<0){
            break;
        }
        cout << t << " "<<h<<endl;
    }

}
