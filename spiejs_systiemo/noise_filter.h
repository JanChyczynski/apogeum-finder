//
// Created by Jasiek on 11.12.2021.
//

#ifndef SPIEJS_SYSTIEMO_NOISE_FILTER_H
#define SPIEJS_SYSTIEMO_NOISE_FILTER_H

#include "params.h"
#include "cyclic_que.h"

class Noise_filter : Cyclic_que<altitude_t, SAMPLES_IN_NOISE_FILTER>
{
    altitude_t sum = 0;
public:
    Noise_filter()
    {
        for (int i = 0; i < SAMPLES_IN_NOISE_FILTER; ++i)
        {
            insert(0);
        }
    }

    altitude_t new_sample(altitude_t sample)
    {
        sum -= get(SAMPLES_IN_NOISE_FILTER-1);
        sum += sample;
        insert(sample);
        return get_value();
    }

    altitude_t get_value()
    {
        return sum/SAMPLES_IN_NOISE_FILTER;
    }
};

#endif //SPIEJS_SYSTIEMO_NOISE_FILTER_H
