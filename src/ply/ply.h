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
        int totalver;
        vector<Eigen::Vector3f> vertexlist;
};

#endif
