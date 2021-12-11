#ifndef APOGEUM_FINDER
#define APOGEUM_FINDER

#include "params.h"
#include "cyclic_que.h"

class Apogeum_finder
{
    bool reached_apogeum = false;

    Cyclic_que<altitude_t, PAST_SAMPLE_COMPARED> alt_que;
    altitude_t max_alt = 0; //TO DO - are defaults OK?
    int sample_cnt = 0;
    altitude_t prev_alt = 0, curr_alt = 0;
    int neg_delta_cnt = 0;
public:

    void insertAltitude(altitude_t altitude)
    {
        sample_cnt++;
        update_altitude(altitude);

        update_neg_streak();
        update_max_alt();

        if (above_minimum_altitude() && (
                (reached_apogeum_by_lower_then_earlier() &&
                reached_apogeum_by_max_alt())
                ||
                definitly_reached_apogeum_by_max_alt()))
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

        alt_que.insert(altitude);
    }

    bool  above_minimum_altitude()
    {
        return alt_que.get(0) > MIN_ALT;
    }

    bool reached_apogeum_by_lower_then_earlier()
    {
        return sample_cnt >= PAST_SAMPLE_COMPARED &&
            alt_que.get(0) < alt_que.get(alt_que.size()-1);
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
    bool definitly_reached_apogeum_by_max_alt()
    {
        return max_alt - curr_alt > MAX_ALT_DIFF_DEFINITE;
    }
};

#endif