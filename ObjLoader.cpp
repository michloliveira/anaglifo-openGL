#include <iostream>
#include "ObjLoader.h"

using namespace std;

void ObjLoader::loadModel(object &Model, const char *filePath){
    cout << "hello" << endl;
}



normal ObjLoader::getNormal(string s){
    float x, y, z;
    sscanf(s.c_str(), "vn %f %f %f", &x, &y, &z);
    normal n(x, y, z);

    return n;
}

vertice ObjLoader::getVertice(string s){
    float x, y, z;
    sscanf(s.c_str(),"v %f %f %f", &x, &y, &z);
    vertice v(x, y, z);

    return v;
}

face ObjLoader::getFace(string s){
    int v0, v1, v2; //vertice
    int vt0, vt1, vt2; //vertice de textura
    int vn0, vn1, vn2; //vertice normal
    sscanf(s.c_str(),"f %d/%d/%d %d/%d/%d %d/%d/%d", &v0, &vt0, &vn0, &v1, &vt1, &v2, &v2, &vt2, &vn2);
    face f(v0,vt0,vn0,v1,vt1,vn1,v2,vt2,vn2);

    return f;
}

