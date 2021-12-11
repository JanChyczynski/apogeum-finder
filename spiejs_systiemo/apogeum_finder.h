#include "params.h"


class Apogeum_finder
{
  altitude_t prev_alt = 0, curr_alt = 0;
  bool reached_apogeum = false;
  public:

  void insertAltitude(altitude_t altitude)
  {
    prev_alt = curr_alt;
    curr_alt = altitude;
  }

  bool get_reached_apogeum()
  {
    return reached_apogeum;
  }
  
};
