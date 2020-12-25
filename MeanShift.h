#pragma once 

#include <vector>
#include <tuple>

using Point = std::vector<double>;
struct Cluster {
    std::vector<double> center;
    std::vector<int> point_indexs;
};

class MeanShift {
public:

    MeanShift() { set_kernel(NULL); }
    MeanShift(double (*_kernel_func)(double,double)) { set_kernel(kernel_func); }
    std::vector<Point> meanshift(const std::vector<Point> & points,
                                                double kernel_bandwidth,
                                                double EPSILON = 0.00001);
    std::tuple<std::vector<Cluster>, std::vector<Point>> fit(const std::vector<Point> &, double);

private:
    double (*kernel_func)(double,double);
    void set_kernel(double (*_kernel_func)(double,double));
    void shift_point(const Point&, const std::vector<Point> &, double, Point&);
    std::vector<Cluster> cluster(const std::vector<Point> &, const std::vector<Point> &);
};
