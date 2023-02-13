#include <iostream>
#include <fstream>
#include <iomanip>
#include "ObjLoader.h"

using namespace std;

void ObjLoader::loadModel(object &Model, const char *filePath){
    cout << setprecision(10);
    fstream arq(filePath);
    string line = "";

    if(arq.is_open()){
        while (getline(arq,line)){
            if(line.find("v ") != string::npos){
                vertice v = getVertice(line);
                Model.vertices.push_back(v);
            }
            else if(line.find("vn ") != string::npos){
                normal n = getNormal(line);
                Model.normais.push_back(n);
            }
            else if(line.find("f ") != string::npos){
                face f = getFace(line);
                Model.faces.push_back(f);
            }
        }
        
        
    }
    else{
        cout << "Erro ao abrir modelo" << endl;
    }
    arq.close();

    // cout << "Quatidade de vertices: " << Model.vertices.size() << endl;
    // cout << "Quatidade de normais: " << Model.normais.size() << endl;
    // cout << "Quatidade de faces: " << Model.faces.size() << endl;
}



normal ObjLoader::getNormal(string s){
    double x, y, z;
    sscanf(s.c_str(), "vn %lf %lf %lf", &x, &y, &z);
    normal n(x, y, z);

    return n;
}

vertice ObjLoader::getVertice(string s){
    double x, y, z;
    sscanf(s.c_str(),"v %lf %lf %lf", &x, &y, &z);
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

