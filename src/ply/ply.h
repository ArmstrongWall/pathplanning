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

#include "../astar/stlastar.h"

using namespace std;

#define horizon_grid_sum    164.0
#define vertical_grids_sum  120.0

// #define horizon_grid_sum    10.0
// #define vertical_grids_sum  12.0

const int MAP_WIDTH = (int)horizon_grid_sum;
const int MAP_HEIGHT = (int)vertical_grids_sum;

const float RATIO_WIDTH  = 1/(((float)MAP_WIDTH)/2);
const float RATIO_HEIGHT = 1/(((float)MAP_HEIGHT)/2);


// Global data

// The world map
long world_map[ (int)horizon_grid_sum*(int)vertical_grids_sum ] = 
{
// // 0001020304050607080910111213141516171819
// 	1,1,1,1,1,1,1,9,1,1,   // 00
// 	1,1,1,1,1,1,9,9,1,1,   // 01
// 	1,1,1,9,9,9,9,9,1,1,   // 02
// 	1,1,1,9,9,9,9,9,1,1,   // 03
// 	1,1,9,9,9,9,9,9,1,1,   // 04
// 	1,1,1,9,9,9,9,9,1,1,   // 05
// 	1,1,1,1,9,9,9,9,1,1,   // 06
// 	1,1,1,1,1,9,9,9,1,1,   // 07
//     1,1,1,1,1,1,1,1,1,1,   // 08
//     1,1,1,1,1,1,1,1,1,1,   // 09
//     1,1,1,1,1,1,1,1,1,1,   // 10
//     1,1,1,1,1,1,1,1,1,1,   // 11
    
    
    
// // 0001020304050607080910111213141516171819
// 	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,   // 00
// 	1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,   // 01
// 	1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 02
// 	1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 03
// 	1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   // 04
// 	1,9,1,1,9,1,1,1,1,9,1,1,1,1,9,1,1,9,1,1,   // 05
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

// map helper functions
//get map grid value
int GetMap( int x, int y )
{   //
	if( x < 0 ||
	    x >= MAP_WIDTH ||
		 y < 0 ||
		 y >= MAP_HEIGHT
	  )
	{
		return 9; 
	}
    
	
	return world_map[(y*MAP_WIDTH)+x];
}


//should be define out of class
bool coor_x_cmp(const Eigen::Vector3f &a , const Eigen::Vector3f &b)
{
    return a(0,0)<b(0,0);
}
bool coor_z_cmp(const Eigen::Vector3f &a , const Eigen::Vector3f &b)
{
    return a(2,0)<b(2,0);
}


class Grid_Map
{
   
public: 
    Grid_Map(){}
    ~Grid_Map(){}
    void make_map(long *world_map);
    void grid_map_display();
    void Display_grid();

private:
    void load(const char* filename);
    void draw();
    vector<Eigen::Vector3f> vertexlist;

private:
    int totalver;
    
private:
    float MAX_vertical;
    float MIN_vertical;
    float MAX_horizon;
    float MIN_horizon;

};




// Definitions

class MapSearchNode
{
public:
	int x;	 // the (x,y) positions of the node
	int y;	
	
	MapSearchNode() { x = y = 0; }
	MapSearchNode( int px, int py ) { x=px; y=py; }

	float GoalDistanceEstimate( MapSearchNode &nodeGoal );
	bool IsGoal( MapSearchNode &nodeGoal );
	bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node );
	float GetCost( MapSearchNode &successor );
	bool IsSameState( MapSearchNode &rhs );

	void PrintNodeInfo();
    //void grid_map_display(void);

};

#endif
