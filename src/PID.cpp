#include "PID.h"
#include <iostream>
#include <math.h>
#include <chrono>

using namespace std;

PID::PID(const PID::Parameters &K, int debug) :
    K_{K[0],K[1],K[2]},
    debug_(debug),
    prev_cte_(0.0),
    int_cte_(0.0),
    n_meas_(0),
    avg_cte_(0.0),
    prev_time_()
{}

PID::~PID() {}

double PID::AvgError() { return avg_cte_; }

double PID::Control(double cte)
{

    double diff_cte = 0.0;
    double delta_t;
    Timestamp t;

    if (int_cte_ == 0.0)
        delta_t = 1.0;
    else
        delta_t = t.diff(prev_time_);

    if (fabs(delta_t)>0.001)
        diff_cte = (cte - prev_cte_) / delta_t;

    int_cte_  += cte * delta_t;
    prev_cte_  = cte;
    prev_time_ = t;

    double output = -K_[0] * cte - K_[1] * diff_cte - K_[2] * int_cte_;

    ++n_meas_;
    avg_cte_ = ((n_meas_-1)*avg_cte_ + cte) / n_meas_;

    if  (debug_>1)
        std::cout << "Output: " << output << "Delta time: " << delta_t << " Integrated CTE: " << int_cte_ << std::endl;

    return output;;
}
