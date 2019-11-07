//
//  Cluster.cpp
//  k-means
//
//  Created by Ayush Tiwari on 05/11/19.
//  Copyright © 2019 Ayush Tiwari. All rights reserved.
//

#define SCALE 20

#include <random>
#include <chrono>
#include <iostream>
#include <algorithm>

#include "Cluster.hpp"
#include "Point.hpp"

Cluster::Cluster(){
    unsigned seed = (unsigned)std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(0.0, SCALE);
    
    this->centroid = new Centroid(distribution(generator), distribution(generator), distribution(generator), distribution(generator));
}

void Cluster::insert(Point p) {
    points.push_back(p);
    label_dict[p.get_label()]++;
}

void Cluster::set_centroid(Centroid centroid) {
    (this->centroid)->set_coordinates(centroid.get_x(), centroid.get_y(), centroid.get_z(), centroid.get_w());
}

Centroid Cluster::get_centroid() {
    return *(this->centroid);
}

std::vector<Point> Cluster::get_points() {
    return points;
}

void Cluster::update_centroid() {
    double cent_x = 0, cent_y = 0, cent_z = 0, cent_w = 0;
    
    for(int i=0; i<points.size(); i++) {
        cent_x += points[i].get_x();
        cent_y += points[i].get_y();
        cent_z += points[i].get_z();
        cent_w += points[i].get_w();
    }
    
    cent_x /= points.size();
    cent_y /= points.size();
    cent_z /= points.size();
    cent_w /= points.size();
    
    centroid->set_coordinates(cent_x, cent_y, cent_z, cent_w);
    
}

void Cluster::clear() {
    points.clear();
    label_dict.clear();
}

std::ostream& operator<<(std::ostream& os, const Cluster& cluster) {
    
    auto iter = cluster.label_dict.begin();
    os << "[";
    os << "{";
    
    while(iter!=cluster.label_dict.end()) {
        os << iter->first << " : " << iter->second << ", ";
        iter++;
    }
    os << "}";
    os << ", ";
    os << *(cluster.centroid);
    os << "]";
    
    return os;
    
}

double Cluster::jaccard_dist(std::string label, int count) {
    
    int _intersection = std::min(label_dict[label], count);
    int _union = (int)points.size() + count - _intersection;
    
    return 1 - double(_intersection)/_union;
    
}
