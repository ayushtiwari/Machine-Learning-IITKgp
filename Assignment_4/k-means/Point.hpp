//
//  Point.hpp
//  k-means
//
//  Created by Ayush Tiwari on 05/11/19.
//  Copyright © 2019 Ayush Tiwari. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#define SCALE 20

#include <vector>
#include <random>
#include <chrono>
#include <string>
#include <iostream>

#include "Cluster.hpp"

class Cluster;

class Point {
private:
    std::string label;
protected:
    double x, y, z, w;
public:
    Point(double x, double y, double z, double w);
    Point(double x, double y, double z, double w, std::string label);
    double get_x();
    double get_y();
    double get_z();
    double get_w();
    std::string get_label();
    double dist(Point p);
    double dist(Cluster cluster);
    int closest_cluster_index(std::vector<Cluster> clusters);
    
    bool operator==(const Point &p);
    
    friend std::ostream& operator<<(std::ostream& os, const Point& point);
};

class Centroid: public Point {
public:
    Centroid(double x, double y, double z, double w);
    void set_coordinates(double x, double y, double z, double w);
};

#endif /* Point_hpp */
