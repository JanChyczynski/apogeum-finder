#ifndef APOGEUM_FINDER
#define APOGEUM_FINDER

#include "params.h"


class Apogeum_finder
{
    altitude_t prev_alt = 0, curr_alt = 0, max_alt; //TO DO
    bool reached_apogeum = false;
    int neg_delta_cnt = 0;
public:

    void insertAltitude(altitude_t altitude)
    {
        update_altitude(altitude);

        update_neg_streak();
        update_max_alt();

        if (reached_apogeum_by_neg_streak() &&
                reached_apogeum_by_max_alt())
        {
            reached_apogeum = true;
        }

    }

    bool get_reached_apogeum()
    {
        return reached_apogeum;
    }

private:
    void update_altitude(altitude_t altitude)
    {
        prev_alt = curr_alt;
        curr_alt = altitude;
    }

    void update_neg_streak()
    {
        altitude_t delta = curr_alt - prev_alt;

        if (delta < 0)
        {
            neg_delta_cnt++;
        } else
        {
            neg_delta_cnt = 0;
        }
    }

    bool reached_apogeum_by_neg_streak()
    {
        return neg_delta_cnt >= NEG_STREAK_REQ;
    }

    void update_max_alt()
    {
        if(curr_alt > max_alt)
        {
            max_alt = curr_alt;
        }
    }

    bool reached_apogeum_by_max_alt()
    {
        return max_alt - curr_alt > MAX_ALT_DIFF_REQ;
    }
};

#endif