#ifndef APOGEUM_FINDER
#define APOGEUM_FINDER

#include "params.h"


class Apogeum_finder
{
  altitude_t prev_alt = 0, curr_alt = 0; //TO DO
  bool reached_apogeum = false;
  int neg_delta_cnt = 0;
  public:

  void insertAltitude(altitude_t altitude)
  {
    prev_alt = curr_alt;
    curr_alt = altitude;

    altitude_t delta = curr_alt - prev_alt;

    if(delta < 0)
    {
        neg_delta_cnt++;
    }
    else
    {
        neg_delta_cnt = 0;
    }

    if(neg_delta_cnt >= NEG_STREAK_REQ)
    {
        reached_apogeum = true;
    }

  }

  bool get_reached_apogeum()
  {
    return reached_apogeum;
  }
  
};

#endif