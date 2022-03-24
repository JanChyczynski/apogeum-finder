#include <bits/stdc++.h>

using namespace std;

double maks = 0;
//example data:
double v = 100.0; //initial velocity
double g = 10.0;//gravity force
int outlier_chance = 0;//from 0 to 100
double chaos_coef = 0.05;//from 0 to 1
double outlier_coef = 3;//how much you like, but above 5 is crazy

int get_data_amount(double v, double g) {
    for (double t = 0; t < 1000; t += 0.1) {
        double h = v * t - g * t * t / 2;
        maks = max(maks, h);
        if (h < 0) {
            return t * 10;
        }
    }
    throw "rocket never goes below zero";
    return -1;
}

double outlier(double h) {
    if (rand() % 100 >= outlier_chance) {
        return h;
    }

    if (rand() % 2) {
        return h * outlier_coef;
    }

    return h / outlier_coef;
}

double getRandomDouble(double min, double max) {
    return ((double) rand() / RAND_MAX) * (max - min) + min;
}

double apply_chaos(double data) {
    data *= getRandomDouble(1.0 - chaos_coef, 1.0 + chaos_coef);
    return outlier(data);
}


int main() {
    cin >> v >> g >> chaos_coef >> outlier_chance >> outlier_coef;
    cout << get_data_amount(v, g) << " " << v * v / (2 * g) << endl;
    srand(v * 97 + g * 37 + chaos_coef * 7 + outlier_chance * 11 + outlier_coef * 23);
    for (double t = 0; t < 1000; t += 0.1) {
        double h = v * t - g * t * t / 2;
        if (h < 0) {
            break;
        }
        cout << setprecision(2) << fixed << t << "\t"
             << apply_chaos(h) << endl;
    }

}
