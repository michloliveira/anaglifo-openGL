#include <iostream>
#include "ObjLoader.h"

using namespace std;

int main(int argc, char *argv[]){
    object bone;
    //ObjLoader *readModel = new ObjLoader();

    ObjLoader readModel;

    readModel.loadModel(bone,"3DModel.obj");

    //readModel->loadModel(bone,"hello");
    for(int i = 0; i< bone.faces.size() ; i++){
        //printf("%.8f %.8f %.8f \n",bone.vertices[bone.faces[i].v[0] -1].x, bone.vertices[bone.faces[i].v[1] -1].y, bone.vertices[bone.faces[i].v[2] -1].z);
        //cout << bone.vertices[bone.faces[i].v[0] -1].x <<" "<< bone.vertices[bone.faces[i].v[1] -1].y << " " <<bone.vertices[bone.faces[i].v[2] -1].z << endl;
        //cout << i <<endl;
    }
    
    return 0;
}
