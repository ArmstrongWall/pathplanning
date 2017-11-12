#include <unistd.h>

#include <iostream>
#include <stdio.h>
#include <math.h>

#include "astar/stlastar.h" // See header for copyright and usage information
#include "ply/ply.h" // See header for copyright and usage information


#define DEBUG_LISTS 0
#define DEBUG_LIST_LENGTHS_ONLY 0

using namespace std;


// Main

int main( int argc, char *argv[] )
{

	// Our sample problem defines the world as a 2d array representing a terrain
	// Each element contains an integer from 0 to 5 which indicates the cost 
	// of travel across the terrain. Zero means the least possible difficulty 
	// in travelling (think ice rink if you can skate) whilst 5 represents the 
	// most difficult. 9 indicates that we cannot pass.

	// Create an instance of the search class...

	AStarSearch<MapSearchNode> astarsearch;

	unsigned int SearchCount = 0;

	const unsigned int NumSearches = 1;
    
    
    Grid_Map* map = new Grid_Map();
    //map->make_map(world_map);
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(400, 100);
    glutInitWindowSize(900, 900);
    glutCreateWindow("机器人路径规划仿真");
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    map->grid_map_display();
    map->Display_grid();

	
    glutMainLoop();
	
	return 0;
}




