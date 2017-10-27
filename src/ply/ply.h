#ifndef _PLY_H_
#define _PLY_H_

#include <iostream>
#include <iterator>
#include <vector>
#include <string>
#include <cstring>
#include <utility>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <GL/glut.h>

#include <Eigen/Core>


using namespace std;


class plyloaddraw
{
public:
    void load(const char* filename);
    void draw();
    vector<Eigen::Vector3f> vertexlist;
private:
    int totalver;
    
};


class Grid_Map
{
public: 
    void make_map(plyloaddraw &ply , vector<Eigen::Vector3f> &grid_map);
    vector<Eigen::Vector3f> Grid_Map;
    
private:
    plyloaddraw ply;
        
};

#endif
