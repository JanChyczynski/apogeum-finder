#include <iostream>
#include "apogeum_finder.h"
#include "params.h"
#include "noise_filter.h"


using namespace std;

int main()
{
    Apogeum_finder apg_finder;
    Noise_filter filter;

    int in_size = 0;
    my_time_t in_apg_time, found_apg_time = -1;
    cin >> in_size >> in_apg_time;
    bool found = false;
    for (int i = 0; i < in_size; ++i)
    {
        altitude_t alt;
        my_time_t time;
        cin  >> time >> alt;
        apg_finder.insertAltitude(filter.new_sample(alt));
        cout << "curr filtered alt: " << filter.get_value() << endl;
        if(!found && apg_finder.get_reached_apogeum())
        {
            cout << "apg_found: time: " << time << " alt: " << alt << endl;
            found_apg_time = time;
            found = true;
        }
    }
    cout << "in apg time: " << in_apg_time << endl;
    cout << "found apg time: " << found_apg_time << endl;
}