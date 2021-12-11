#ifndef PARAMS
#define PARAMS

typedef double altitude_t;
typedef int my_time_t;

const int PAST_SAMPLE_COMPARED = 10;
const int NEG_STREAK_REQ = 5;
const altitude_t MIN_ALT = 5; //meter
const altitude_t MAX_ALT_DIFF_REQ = 1; //meter
const altitude_t MAX_ALT_DIFF_DEFINITE = 3; //meter
const int SAMPLES_IN_NOISE_FILTER = 10;

#endif
