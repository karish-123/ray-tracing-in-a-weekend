#ifndef INTERVAL_H
#define INTERVAL_H

#include <limits> // <-- include this for std::numeric_limits

class interval {
  public:
    double min, max;

    interval()
        : min(+std::numeric_limits<double>::infinity()),
          max(-std::numeric_limits<double>::infinity()) {}

    interval(double min, double max) : min(min), max(max) {}

    double size() const {
        return max - min;
    }

    bool contains(double x) const {
        return min <= x && x <= max;
    }

    bool surrounds(double x) const {
        return min < x && x < max;
    }
    double clamp(double x) const {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }

    static const interval empty, universe;
};

// Define static members
const interval interval::empty = interval(
    +std::numeric_limits<double>::infinity(),
    -std::numeric_limits<double>::infinity());

const interval interval::universe = interval(
    -std::numeric_limits<double>::infinity(),
    +std::numeric_limits<double>::infinity());

#endif
