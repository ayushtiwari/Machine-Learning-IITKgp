//
//  Utilities.hpp
//  k-means
//
//  Created by Ayush Tiwari on 05/11/19.
//  Copyright © 2019 Ayush Tiwari. All rights reserved.
//

#ifndef Utilities_hpp
#define Utilities_hpp

#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include <functional>
#include <locale>
#include <algorithm>
   

#include "Point.hpp"

class Utilites {
public:
    
    static std::vector<std::string> split(std::string line, char c) {
        std::vector<std::string> words;

        std::string::iterator iter = line.begin();
        std::string::iterator pos;

        while(iter!=line.end()) {
            pos = find(iter, line.end(), c);
            words.push_back(std::string(iter, pos));
            if(pos==line.end()) break;
            iter = pos+1;
        }

        return words;
    }
    
    static void read_from_file(std::string filepath, std::vector<Point> &points, std::map<std::string, int> &label_dictionary) {
        
        std::fstream file;
        file.open(filepath);
        
        std::string line;
        
        while(getline(file, line)) {
            
//            std::cout << line << std::endl;
            
            std::vector<std::string> words = split(line, ',');
            
            if(words.size()!=5) continue;
            
            label_dictionary[words[4]]++;
            
            double x = stof(words[0]);
            double y = stof(words[1]);
            double z = stof(words[2]);
            double w = stof(words[3]);

            points.push_back(Point(x, y, z, w, words[4]));
            
        }
        
    }
};

#endif /* Utilities_hpp */
