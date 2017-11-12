#include "ply.h"

void Grid_Map::load(const char* filename)
{
	printf("Loading %s...\n",filename);
    const char* pch = strstr(filename,".ply");

    if (pch != NULL)//check file is .ply
    {
        FILE* file = fopen(filename,"r");//read open file
        if (!file)                    
        {
            printf("load PLY file %s failed\n",filename);
        }
    
        fseek(file,0,SEEK_SET);
         //move file pointer to file begin
 
        if (file)
        {
            char buffer[1000];
            fgets(buffer,300,file);
            //read every line data in ply file to buffer
            while (  strncmp( "element vertex", buffer,strlen("element vertex")) != 0  )
            //alawys read until meet "element vertex"
            {
                fgets(buffer,300,file);			
            }
            strcpy(buffer, buffer+strlen("element vertex"));   
            //record vertex numbers
            sscanf(buffer,"%d", &totalver);                    
            //copy 
            cout << "totalver = " << totalver << endl;
            while (  strncmp( "end_header", buffer,strlen("end_header")) != 0  )
            {
                fgets(buffer,300,file);
            }
            for (int iterator = 0; iterator < totalver; iterator++)
            {
                
                fgets(buffer,300,file);
                Eigen::Vector3f temp;
                sscanf(buffer,"%f %f %f ", &temp(0,0) , & temp(1,0), & temp(2,0));
                //cout<<temp(0,0)<<"   "<<temp(1,0)<<"   "<<temp(2,0)<<"\n";
                vertexlist.push_back(temp);
            }
            //cout << vertexlist.size() << endl;
            fclose(file);
            printf("%s Loaded!\n",filename);
    
        }
        else 
        { 
            printf("File can't be opened\n");
        }
    }	
    else 
    {
        printf("File does not have a .PLY extension. ");    
    }   
}
 
void Grid_Map::make_map(long world_map[])
{
    load("lab_stand_use.ply");
    cout << vertexlist.size() << endl;
    sort(vertexlist.begin(),vertexlist.end(),coor_z_cmp);
    MAX_horizon = vertexlist[totalver-1](2,0);
    MIN_horizon = vertexlist[0](2,0);
    //cout << "MAX_horizon= " << MAX_horizon << endl;
    //cout << "MIN_horizon= " << MIN_horizon << endl; 
    
    sort(vertexlist.begin(),vertexlist.end(),coor_x_cmp);
    MAX_vertical = vertexlist[totalver-1](0,0);
    MIN_vertical = vertexlist[0](0,0);
    //cout << "MAX_vertical= " << MAX_vertical << endl;
    //cout << "MIN_vertical= " << MIN_vertical << endl;  
    
    float horizon_unit = (MAX_horizon-MIN_horizon)/horizon_grid_sum;
    float vertical_unit = (MAX_vertical-MIN_vertical)/vertical_grids_sum;
    
    for(int i = 0 ; i < (int)vertical_grids_sum*(int)horizon_grid_sum ; i++)
    {
        world_map[i]  = 0;
    }
//     for(int i = 0 ; i < (int)vertical_grids_sum*(int)horizon_grid_sum ; i++)
//     {
//         cout << "world_map" << i << " = " << world_map[i] << endl;
//     }
  
    for(long i = 0 ; i < totalver ; i++)
    {
        long cord = (int)((vertexlist[i](0,0) - MIN_vertical)/vertical_unit) * (int)horizon_grid_sum
                   + (int)((vertexlist[i](2,0) - MIN_horizon)/horizon_unit);//memtion: coor = y*horizon + x
        world_map[cord] ++;
    }
    for(int i = 0 ; i < (int)vertical_grids_sum*(int)horizon_grid_sum ; i++)
    {
        if( world_map[i] >= 10 )
            world_map[i]  = 9;
        else if( world_map[i] < 10 )
            world_map[i]  = 1;
    }
    
    //long sum;
//     for(int i = 0 ; i < (int)vertical_grids_sum*(int)horizon_grid_sum ; i++)
//     {
//         //sum += world_map[i];
//         cout <<  "      " << world_map[i] ;
//         if( (i+1)%(int)horizon_grid_sum ==0  )
//             cout << endl ;
//     }
    
}

void Grid_Map::grid_map_display(void)
{
    int width =0 , height= 0;
    float leftupper_coor = 0.0,rightdown_coor = 0.0;
   

    for(width = 0; width < MAP_WIDTH; width++)
    {
        for(height = 0; height < MAP_HEIGHT; height++)
        {
            leftupper_coor = -1 + width*RATIO_WIDTH;
            rightdown_coor =  1 - height*RATIO_HEIGHT;
            if(GetMap(width,height)==1)//pass
            {
                glColor3ub(0 ,255 ,127);//green
                glRectf(leftupper_coor,rightdown_coor,leftupper_coor+RATIO_WIDTH,rightdown_coor-RATIO_HEIGHT);
            }
            else if(GetMap(width,height)==9)//barrior
            {
                glColor3ub(250, 128 ,114);//red
                glRectf(leftupper_coor,rightdown_coor,leftupper_coor+RATIO_WIDTH,rightdown_coor-RATIO_HEIGHT);
            } 
            
        }
           
    }
      
     glFlush();        

}

void Grid_Map::Display_grid(void)
{
    int width =0 , height= 0;
    
    glLineWidth(0.5f); //设置线宽
    glColor3ub(0, 0 ,0);
    
    for(width = 0; width <= MAP_WIDTH ; width++)
    {
        glBegin(GL_LINES);
            glVertex2f(-1 + width*RATIO_WIDTH, 1.0f);
            glVertex2f(-1 + width*RATIO_WIDTH, -1.0f);
        glEnd();
    }
    for(height = 0; height <= MAP_HEIGHT ; height++)
    {
        glBegin(GL_LINES);
            glVertex2f(-1.0f, 1 - height*RATIO_HEIGHT);
            glVertex2f( 1.0f, 1 - height*RATIO_HEIGHT);
        glEnd();
    }
      
    glFlush();  
}



bool MapSearchNode::IsSameState( MapSearchNode &rhs )
{
//judge is SameState
	// same state in a maze search is simply when (x,y) are the same
	if( (x == rhs.x) &&
		(y == rhs.y) )
	{
		return true;
	}
	else
	{
		return false;
	}

}

void MapSearchNode::PrintNodeInfo()
{
	char str[100];
	sprintf( str, "Node position : (%d,%d)\n", x,y );
	cout << str;
    
    float leftupper_coor = 0.0,rightdown_coor = 0.0;
    
    leftupper_coor = -1 + x*RATIO_WIDTH;
    rightdown_coor =  1 - y*RATIO_HEIGHT;
    glColor3ub(152 ,245 ,255);
    glRectf(leftupper_coor+0.002,rightdown_coor-0.002,leftupper_coor+RATIO_WIDTH-0.002,rightdown_coor-RATIO_HEIGHT+0.006);
    
    glFlush();
    
    //usleep(1000*100);
}

// Here's the heuristic function that estimates the distance from a Node
// to the Goal. 

float MapSearchNode::GoalDistanceEstimate( MapSearchNode &nodeGoal )
{//manhattan distance
	return fabsf(x - nodeGoal.x) + fabsf(y - nodeGoal.y);
}

bool MapSearchNode::IsGoal( MapSearchNode &nodeGoal )
{

	if( (x == nodeGoal.x) &&
		(y == nodeGoal.y) )
	{
		return true;
	}

	return false;
}

// This generates the successors to the given Node. It uses a helper function called
// AddSuccessor to give the successors to the AStar class. The A* specific initialisation
// is done for each node internally, so here you just set the state information that
// is specific to the application
bool MapSearchNode::GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node )
{

	int parent_x = -1; 
	int parent_y = -1;

	if( parent_node )
	{
		parent_x = parent_node->x;
		parent_y = parent_node->y;
	}
	

	MapSearchNode NewNode;

	// push each possible move except allowing the search to go backwards

	if( (GetMap( x-1, y ) < 9) 
		&& !((parent_x == x-1) && (parent_y == y))
	  ) 
	{
		NewNode = MapSearchNode( x-1, y );
		astarsearch->AddSuccessor( NewNode );
	}	

	if( (GetMap( x, y-1 ) < 9) 
		&& !((parent_x == x) && (parent_y == y-1))
	  ) 
	{
		NewNode = MapSearchNode( x, y-1 );
		astarsearch->AddSuccessor( NewNode );
	}	

	if( (GetMap( x+1, y ) < 9)
		&& !((parent_x == x+1) && (parent_y == y))
	  ) 
	{
		NewNode = MapSearchNode( x+1, y );
		astarsearch->AddSuccessor( NewNode );
	}	

		
	if( (GetMap( x, y+1 ) < 9) 
		&& !((parent_x == x) && (parent_y == y+1))
		)
	{
		NewNode = MapSearchNode( x, y+1 );
		astarsearch->AddSuccessor( NewNode );
	}
	
	if( (GetMap( x+1, y+1 ) < 9) 
		&& !((parent_x == x+1) && (parent_y == y+1))
		)
	{
		NewNode = MapSearchNode( x+1, y+1 );
		astarsearch->AddSuccessor( NewNode );
	}
	
	if( (GetMap( x+1, y-1 ) < 9) 
		&& !((parent_x == x+1) && (parent_y == y-1))
		)
	{
		NewNode = MapSearchNode( x+1, y-1 );
		astarsearch->AddSuccessor( NewNode );
	}
	
	if( (GetMap( x-1, y+1 ) < 9) 
		&& !((parent_x == x-1) && (parent_y == y+1))
		)
	{
		NewNode = MapSearchNode( x-1, y+1 );
		astarsearch->AddSuccessor( NewNode );
	}
	
	if( (GetMap( x-1, y-1 ) < 9) 
		&& !((parent_x == x-1) && (parent_y == y-1))
		)
	{
		NewNode = MapSearchNode( x-1, y-1 );
		astarsearch->AddSuccessor( NewNode );
	}

	return true;
}

// given this node, what does it cost to move to successor. In the case
// of our map the answer is the map terrain value at this node since that is 
// conceptually where we're moving

float MapSearchNode::GetCost( MapSearchNode &successor )
{
	return (float) GetMap( x, y );

}

