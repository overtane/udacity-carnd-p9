#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <chrono>

class Timestamp {

private:
  std::chrono::high_resolution_clock::time_point t_;
    
public:
    Timestamp() : t_(std::chrono::high_resolution_clock::now()) {}
    virtual ~Timestamp() {}

    double diff(Timestamp &t2) {
      std::chrono::duration<double> diff = std::chrono::duration_cast<std::chrono::duration<double>>(t_ - t2.t_);
      return diff.count();
    }

};

#endif
