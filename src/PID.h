#ifndef PID_H
#define PID_H

#include "Timestamp.h"

class PID {

public:

  typedef double Parameters[3];

  /**
   * Constructor
   */
  PID(const PID::Parameters &, int);

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   *  Given a cross track error and time delta, calculate controlled output
   */
  double Control(double cte);

  double AvgError();

 private:

  PID();

  const PID::Parameters K_; // controller coefficiens

  int debug_;

  double prev_cte_;     // previous cte 
  double int_cte_;      // integrated cte
  int n_meas_;          // number of measurements
  double avg_cte_;      // average error
  Timestamp prev_time_; // time of previous cte
};

#endif /* PID_H */
