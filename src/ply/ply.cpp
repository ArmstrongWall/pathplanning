#include "ply.h"

void plyloaddraw::load(const char* filename)
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
 
void Grid_Map::make_map(plyloaddraw& ply, vector<Eigen::Vector3f>& grid_map)
{
    ply.vertexlist();
    
    
}


