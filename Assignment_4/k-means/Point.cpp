//
//  Point.cpp
//  k-means
//
//  Created by Ayush Tiwari on 05/11/19.
//  Copyright © 2019 Ayush Tiwari. All rights reserved.

#include "Point.hpp"

Point::Point(double x, double y, double z, double w):x(x), y(y), z(z), w(w), label("Not Defined") {}

Point::Point(double x, double y, double z, double w, std::string label):x(x), y(y), z(z), w(w), label(label) {}

double Point::get_x() { return x; }
double Point::get_y() { return y; }
double Point::get_z() { return z; }
double Point::get_w() { return w; }
std::string Point::get_label() { return label; }

double Point::dist(Point p) {
    return (this->x - p.x)*(this->x - p.x) + (this->y - p.y)*(this->y - p.y) + (this->z - p.z)*(this->z - p.z) + (this->w - p.w)*(this->w - p.w);
}


double Point::dist(Cluster cluster) {
    
    double x = (cluster.get_centroid()).get_x();
    double y = (cluster.get_centroid()).get_y();
    double z = (cluster.get_centroid()).get_z();
    double w = (cluster.get_centroid()).get_w();
    
    return (this->x - x)*(this->x - x) + (this->y - y)*(this->y - y) + (this->z - z)*(this->z - z) + (this->w - w)*(this->w - w);
}

int Point::closest_cluster_index(std::vector<Cluster> clusters) {
    
    if(clusters.empty()) return -1;
    
    int closest_index = 0;
    double closest_dist = dist(clusters[0]);
    
    for(int i=1; i<clusters.size(); i++) {
        if(this->dist(clusters[i]) < closest_dist) {
            closest_dist = dist(clusters[i]);
            closest_index = i;
        }
    }
    
    return closest_index;
}

bool Point::operator==(const Point &p) {
    return x == p.x && y == p.y && z == p.z && w == p.w;
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << "(" << point.x << ", " << point.y << ", " << point.z << ", "<< point.w << ")";
    return os;
}

Centroid::Centroid(double x, double y, double z, double w):Point(x, y, z, w) {}

void Centroid::set_coordinates(double x, double y, double z, double w) {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}
