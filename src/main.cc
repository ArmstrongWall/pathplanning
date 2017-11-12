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
    map->make_map(world_map);
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(400, 100);
    glutInitWindowSize(horizon_grid_sum*9, vertical_grids_sum*9);
    glutCreateWindow("机器人路径规划仿真");
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    map->grid_map_display();
    map->Display_grid();

	while(SearchCount < NumSearches)
	{

		// Create a start state
		MapSearchNode nodeStart;
		nodeStart.x = 56;
		nodeStart.y = 45; 
        
		// Define the goal state
		MapSearchNode nodeEnd;
		nodeEnd.x = 120;						
		nodeEnd.y = 70; 
		
        nodeStart.PrintNodeInfo();
        cout << "nodeStart.x " << nodeStart.x << endl << "nodeStart.y " << nodeStart.y << endl;
        
        nodeEnd.PrintNodeInfo();
        cout << "nodeEnd.x " << nodeEnd.x << endl << "nodeEnd.y " << nodeEnd.y << endl;
		// Set Start and goal states
		
		astarsearch.SetStartAndGoalStates( nodeStart, nodeEnd );

		unsigned int SearchState;
		unsigned int SearchSteps = 0;

		do
		{
			SearchState = astarsearch.SearchStep();

			SearchSteps++;

	#if DEBUG_LISTS

			cout << "Steps:" << SearchSteps << "\n";

			int len = 0;

			cout << "Open:\n";
			MapSearchNode *p = astarsearch.GetOpenListStart();
			while( p )
			{
				len++;
	#if !DEBUG_LIST_LENGTHS_ONLY			
				((MapSearchNode *)p)->PrintNodeInfo();
	#endif
				p = astarsearch.GetOpenListNext();
				
			}

			cout << "Open list has " << len << " nodes\n";

			len = 0;

			cout << "Closed:\n";
			p = astarsearch.GetClosedListStart();
			while( p )
			{
				len++;
	#if !DEBUG_LIST_LENGTHS_ONLY			
				p->PrintNodeInfo();
	#endif			
				p = astarsearch.GetClosedListNext();
			}

			cout << "Closed list has " << len << " nodes\n";
	#endif

		}
		while( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );

		if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED )
		{
			cout << "Search found goal state\n";

				MapSearchNode *node = astarsearch.GetSolutionStart();

	#if DISPLAY_SOLUTION
				cout << "Displaying solution\n";
	#endif
				int steps = 0;
                                
				node->PrintNodeInfo();
				for( ;; )
				{
					node = astarsearch.GetSolutionNext();
                    
                    

					if( !node )
					{
						break;
					}

					node->PrintNodeInfo();
					steps ++;
				
				};

				cout << "Solution steps " << steps << endl;

				// Once you're done with the solution you can free the nodes up
				astarsearch.FreeSolutionNodes();

	
		}
		else if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED ) 
		{
			cout << "Search terminated. Did not find goal state\n";
		
		}

		// Display the number of loops the search went through
		cout << "SearchSteps : " << SearchSteps << "\n";

		SearchCount ++;

		astarsearch.EnsureMemoryFreed();
	}
	
  
	
    glutMainLoop();
	
	return 0;
}




