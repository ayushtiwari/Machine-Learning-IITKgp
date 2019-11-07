//
//  KMeans.cpp
//  k-means
//
//  Created by Ayush Tiwari on 05/11/19.
//  Copyright © 2019 Ayush Tiwari. All rights reserved.
//

#include <random>
#include <iostream>

#include "KMeans.hpp"

KMeans::KMeans(std::vector<Point> points, int no_of_clusters):points(points), no_of_clusters(no_of_clusters) {
    clusters.resize(no_of_clusters);
    this->init_cluster_centroids();
};

void KMeans::train(int no_of_rounds) {
    
    std::cout << "Format -> Cluster i : [{label_dict}, (centroid)]" << std::endl << std::endl;
    
    for(int i=0; i<no_of_rounds; i++) {
        
        std::cout << "Round " << i+1 << " " << std::string(20, '-') << std::endl << std::endl;
        
        for(int i=0; i<clusters.size(); i++)
            clusters[i].clear();
        
        update_clusters();
        
        for(int i=0; i<clusters.size(); i++) {
            std::cout << "Cluster " << i+1 << " : ";
            clusters[i].update_centroid();
            std::cout << std::endl << clusters[i] << std::endl;
        }
        
        std::cout << "\n\n" << std::string(30, '*') << "\n\n";
    }
    
}

void KMeans::update_clusters() {
    for(int i=0; i<points.size(); i++) {
        int closest_cluster_index = points[i].closest_cluster_index(clusters);
        clusters[closest_cluster_index].insert(points[i]);
    }
}

void KMeans::init_cluster_centroids() {
    
    unsigned seed = (unsigned)std::chrono::system_clock::now().time_since_epoch().count();
    
    shuffle (points.begin(), points.end(), std::default_random_engine(seed));
    
    for(int i=0; i<no_of_clusters; i++)
        clusters[i].set_centroid(Centroid(points[i].get_x(), points[i].get_y(), points[i].get_z(), points[i].get_w()));
    
}

std::vector<Cluster> KMeans::get_clusters() {
    return this->clusters;
}

void KMeans::jaccard(std::map<std::string, int> ground_truth) {
    
    std::cout << "Format : Jaccard(Ground Truth Cluster, Cluster i)" << std::endl << std::endl;
    
    auto iter = ground_truth.begin();
    
    int j = 0;
    while(iter != ground_truth.end()) {
        for(int i=0; i<clusters.size(); i++) {
            std::cout << "Jaccard(" << iter->first << ", " << i+1 << ")" << " : " << clusters[i].jaccard_dist(iter->first, iter->second) << std::endl;
        }
        
        std::cout << std::endl;
        
        j++;
        iter++;
    }
    
}
