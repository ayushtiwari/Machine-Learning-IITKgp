//
//  KMeans.hpp
//  k-means
//
//  Created by Ayush Tiwari on 05/11/19.
//  Copyright © 2019 Ayush Tiwari. All rights reserved.
//

#ifndef KMeans_hpp
#define KMeans_hpp

#include <vector>
#include <map>
#include <string>

#include "Point.hpp"
#include "Cluster.hpp"

class Point;
class Cluster;

class KMeans {
    int no_of_clusters;             // No of Clusters
    std::vector<Point> points;      // Points
    std::vector<Cluster> clusters;  // Clusters
    
public:
    
    KMeans(std::vector<Point> points, int no_of_clusters);
    void train(int no_of_rounds);
    void update_clusters();
    void init_cluster_centroids();
    void jaccard(std::map<std::string, int> ground_truth);
    std::vector<Cluster> get_clusters();
    
};

#endif /* KMeans_hpp */
