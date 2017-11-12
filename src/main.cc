#include <unistd.h>

#include <iostream>
#include <stdio.h>
#include <math.h>

#include "astar/stlastar.h" // See header for copyright and usage information
#include "ply/ply.h" // See header for copyright and usage information


using namespace std;


// Main

int main( int argc, char *argv[] )
{

	   
    
    Grid_Map* map = new Grid_Map();

    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(400, 100);
    glutInitWindowSize(900, 900);
    glutCreateWindow("机器人路径规划仿真");

    
    glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();  //black back ground
    map->grid_map_display();
    map->Display_grid();

	
    glutMainLoop();
	
	return 0;
}




