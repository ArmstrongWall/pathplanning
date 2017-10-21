#include <GL/glut.h>
#include <unistd.h>

// The world map

const int MAP_WIDTH = 20;
const int MAP_HEIGHT = 20;

const float RATIO_WIDTH  = 1/(((float)MAP_WIDTH)/2);
const float RATIO_HEIGHT = 1/(((float)MAP_HEIGHT)/2);

int world_map[ MAP_WIDTH * MAP_HEIGHT ] = 
{

// 0001020304050607080910111213141516171819
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,   // 00
	1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,   // 01
	1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 02
	1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 03
	1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   // 04
	1,9,1,1,9,1,1,1,1,9,1,1,1,1,9,1,1,1,1,1,   // 05
	1,9,9,9,9,1,1,1,1,1,1,9,9,9,9,1,1,1,1,1,   // 06
	1,9,9,9,9,9,9,9,9,1,1,1,9,9,9,9,9,9,9,1,   // 07
	1,9,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,   // 08
	1,9,1,9,9,9,9,9,9,9,1,1,9,9,9,9,9,9,9,1,   // 09
	1,9,1,1,1,1,9,1,1,9,1,1,1,1,1,1,1,1,1,1,   // 10
	1,9,9,9,9,9,1,9,1,9,1,9,9,9,9,9,1,1,1,1,   // 11
	1,9,1,9,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 12
	1,9,1,9,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 13
	1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   // 14
	1,9,1,1,9,1,1,1,1,9,1,1,1,1,9,1,1,1,1,1,   // 15
	1,9,9,9,9,1,1,1,1,1,1,9,9,9,9,1,1,1,1,1,   // 16
	1,1,9,9,9,9,9,9,9,1,1,1,9,9,9,1,9,9,9,9,   // 17
	1,9,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,   // 18
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,   // 19

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


void grid_map_display(void)
{
    int width =0 , height= 0;
    float leftupper_coor = 0.0,rightdown_coor = 0.0;
    glClear(GL_COLOR_BUFFER_BIT);
    for(width = 0; width < MAP_WIDTH; width++)
    {
        for(height = 0; height < MAP_HEIGHT; height++)
        {
            leftupper_coor = -1 + width*RATIO_WIDTH;
            rightdown_coor =  1 - height*RATIO_HEIGHT;
            if(GetMap(width,height)==1)
            {
                glColor3f(0.5f, 0.6f, 0.4f);
                glRectf(leftupper_coor,rightdown_coor,leftupper_coor+RATIO_WIDTH,rightdown_coor-RATIO_HEIGHT);
            }
            else if(GetMap(width,height)==9)
            {
                glColor3f(0.0f, 0.3f, 0.5f);
                glRectf(leftupper_coor,rightdown_coor,leftupper_coor+RATIO_WIDTH,rightdown_coor-RATIO_HEIGHT);
            }
            
            glFlush();
        }
        
           
    }
   
            

    return;
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(0, 0); 
    glutInitWindowSize(300, 300);
    glutCreateWindow("OpenGL 3D View");
    glutDisplayFunc(grid_map_display);
    glutMainLoop();

    return 0;
}
