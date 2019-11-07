//
//  Cluster.hpp
//  k-means
//
//  Created by Ayush Tiwari on 05/11/19.
//  Copyright © 2019 Ayush Tiwari. All rights reserved.
//

#ifndef Cluster_hpp
#define Cluster_hpp

#include <vector>
#include <map>
#include <string>

#include "Point.hpp"

class Point;
class Centroid;

class Cluster {
    std::vector<Point> points;
    std::map<std::string, int> label_dict;
    Centroid *centroid;
public:
    Cluster();
    void init();
    void insert(Point p);
    void set_centroid(Centroid centroid);
    Centroid get_centroid();
    std::vector<Point> get_points();
    void update_centroid();
    double jaccard_dist(std::string label, int count);
    void clear();
    
    friend std::ostream& operator<<(std::ostream& os, const Cluster& cluster);
};

#endif /* Cluster_hpp */
