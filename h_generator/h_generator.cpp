#include <bits/stdc++.h>
using namespace std;
double maks=0;
int outlier_chance=0;
double wsp_chaosu=1.5;
double wsp_outliera=3;
int ile_danych(double v,double g){
    for (double t=0;t<1000;t+=0.1){
        double h = v*t-g*t*t/2;
        maks=max(maks,h);
        if (h<0){
            return t*10;
        }
    }
    cout << "o kurwa";
    return -1;
}

double outlier(double h){
    if (rand()%100<outlier_chance){
        if (rand()%2){
            return h*wsp_outliera;
        }else{
            return h/wsp_outliera;
        }
    }
    return h;
}


int main(){
    double v, g;//przyspieszenie, tlumienie
    cin >> v>>g>>wsp_chaosu>>outlier_chance>>wsp_outliera;
    cout <<ile_danych(v,g)<<" "<< v*v/(2*g)<<endl;
    srand(v*97+g*37+wsp_chaosu*7+outlier_chance*11+wsp_outliera*23);
    //cout << ile_danych(v,g)<<" ";
    //cout << maks<<endl;
    double h_past=0;
    for (double t=0;t<1000;t+=0.1){
        double h = v*t-g*t*t/2;
        if (h<0){
            break;
        }
        cout <<setprecision(2)<<fixed<<t<< "\t"<<outlier(h+rand()%(max(0,(int)(wsp_chaosu*(h_past-h)))+1))<<endl;
        h_past=h;
    }

}
