/*
 * Auther: Johnny Wang
 * Date:2017.11.8
 */

#ifndef _ASTAR_H_
#define _ASTAR_H_

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

#include "../astar/stlastar.h"

using namespace std;

#define vertical_grids_sum  120.0
#define horizon_grid_sum    136.0

const int MAP_WIDTH = (int)horizon_grid_sum;
const int MAP_HEIGHT = (int)vertical_grids_sum;

const float RATIO_WIDTH  = 1/(((float)MAP_WIDTH)/2);
const float RATIO_HEIGHT = 1/(((float)MAP_HEIGHT)/2);


// Global data

// The world map
long world_map[ (int)horizon_grid_sum*(int)vertical_grids_sum ] = 
{

// // 0001020304050607080910111213141516171819
// 	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,   // 00
// 	1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,   // 01
// 	1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 02
// 	1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 03
// 	1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   // 04
// 	1,9,1,1,9,1,1,1,1,9,1,1,1,1,9,1,1,1,1,1,   // 05
// 	1,9,9,9,9,1,1,1,1,1,1,9,9,9,9,1,1,1,1,1,   // 06
// 	1,9,9,9,9,9,9,9,9,1,1,1,9,9,9,9,9,9,9,1,   // 07
// 	1,9,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,   // 08
// 	1,9,1,9,9,9,9,9,9,9,1,1,9,9,9,9,9,9,9,1,   // 09
// 	1,9,1,1,1,1,9,1,1,9,1,1,1,1,1,1,1,1,1,1,   // 10
// 	1,9,9,9,9,9,1,9,1,9,1,9,9,9,9,9,1,1,1,1,   // 11
// 	1,9,1,9,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 12
// 	1,9,1,9,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 13
// 	1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   // 14
// 	1,9,1,1,9,1,1,1,1,9,1,1,1,1,9,1,1,1,1,1,   // 15
// 	1,9,9,9,9,1,1,1,1,1,1,9,9,9,9,1,1,1,1,1,   // 16
// 	1,1,9,9,9,9,9,9,9,1,1,1,9,9,9,1,9,9,9,9,   // 17
// 	1,9,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,   // 18
// 	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,   // 19

};

struct Node{
    int f;
    int g;
    int h;
    Node* parent;
};



#endif
