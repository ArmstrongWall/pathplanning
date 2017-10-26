#include "ply.h"

void plyloaddraw::load(const char* filename)
{
	printf("Loading %s...\n",filename);
    const char* pch = strstr(filename,".ply");

    if (pch != NULL)                                     //�����ļ��Ƿ���.ply�ļ�
    {
        FILE* file = fopen(filename,"r");                   //��ֻ����ʽ��file
        if (!file)                                          //���file��������ִ��if�ڲ����
        {
            printf("load PLY file %s failed\n",filename);
        }

        fseek(file,0,SEEK_END);                              //���ļ��ڲ�ָ���Ƶ�ĩβ��offsetΪ0����ָ��ͣ���ļ�ĩβ��

        long fileSize = ftell(file);                         //��¼�ļ����ȣ�fileָ��������ļ��׵�ƫ����
    
        fseek(file,0,SEEK_SET);                              //ָ���Ƶ��ļ���ͷλ��
 
        if (file)
        {
            char buffer[1000];
            fgets(buffer,300,file);			                //��ȡply������,ÿ�ζ�һ�е�buffer��.
 
            while (  strncmp( "element vertex", buffer,strlen("element vertex")) != 0  )//��ȡ����һ�����û��element vertex�ַ��������������һ�У�����������ѭ�����д���
            {
                fgets(buffer,300,file);			
            }
            strcpy(buffer, buffer+strlen("element vertex"));   //����vertex����һ�еĺ���ĵ��������¼����
            sscanf(buffer,"%d", &totalver);                    //��buffer�ж����ݣ���ʮ���Ƶ���ʽ�浽vertexlist��
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


