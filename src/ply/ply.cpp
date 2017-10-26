#include "ply.h"

void plyloaddraw::load(const char* filename)
{
	printf("Loading %s...\n",filename);
    const char* pch = strstr(filename,".ply");

    if (pch != NULL)                                     //检查该文件是否是.ply文件
    {
        FILE* file = fopen(filename,"r");                   //以只读方式打开file
        if (!file)                                          //如果file不存在则执行if内部语句
        {
            printf("load PLY file %s failed\n",filename);
        }

        fseek(file,0,SEEK_END);                              //把文件内部指针移到末尾，offset为0，故指针停在文件末尾处

        long fileSize = ftell(file);                         //记录文件长度，file指针相对于文件首的偏移量
    
        fseek(file,0,SEEK_SET);                              //指针移到文件开头位置
 
        if (file)
        {
            char buffer[1000];
            fgets(buffer,300,file);			                //读取ply中数据,每次读一行到buffer中.
 
            while (  strncmp( "element vertex", buffer,strlen("element vertex")) != 0  )//读取的这一行如果没有element vertex字符串，则继续读下一行，若有则跳出循环进行处理
            {
                fgets(buffer,300,file);			
            }
            strcpy(buffer, buffer+strlen("element vertex"));   //把是vertex的那一行的后面的点的总数记录下来
            sscanf(buffer,"%d", &totalver);                    //从buffer中读数据，以十进制的形式存到vertexlist中
            //sscanf(buffer,"%d", &totalnor);
            cout << "totalver = " << totalver << endl;
            
                      
            while (  strncmp( "end_header", buffer,strlen("end_header")) != 0  )
            {
                fgets(buffer,300,file);			
            }


	   
            for (int iterator = 0; iterator < totalver; iterator++)
            {
                
                fgets(buffer,300,file);
                Eigen::Vector3f temp;
                sscanf(buffer,"%f %f %f ", &temp(0) , & temp(1), & temp(2));
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
 
//vassist

void plyloaddraw::draw()
{

	   

}


