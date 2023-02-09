#include <iostream>
#include "ObjLoader.h"

using namespace std;

int main(int argc, char *argv[]){
    object bone;
    //ObjLoader *readModel = new ObjLoader();

    ObjLoader readModel;

    readModel.loadModel(bone,"3DModel.obj");

    //readModel->loadModel(bone,"hello");
    
    return 0;
}
