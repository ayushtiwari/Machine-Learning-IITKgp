//
//  main.cpp
//  k-means
//
//  Created by Ayush Tiwari on 05/11/19.
//  Copyright © 2019 Ayush Tiwari. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <unordered_map>

#include "KMeans.hpp"
#include "Utilities.hpp"

int main() {

    std::vector<Point> points;
    
    std::map<std::string, int> ground_truth;
    Utilites::read_from_file("data4_19.csv", points, ground_truth);
    
    KMeans kmeans = KMeans(points, 3);

    kmeans.train(10);
    
    kmeans.jaccard(ground_truth);

    return 0;
}
