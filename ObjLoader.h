#include <vector>
#include <string>

struct face{
    int v[3];
    int vt[3];
    int vn[3];
    face(int _v0, int _vt0, int _vn0, int _v1, int _vt1, int _vn1, int _v2, int _vt2, int _vn2){
        v[0] = _v0;
        vt[0] = _vt0;
        vn[0] = _vn0;

        v[1] = _v1;
        vt[1] = _vt1;
        vn[1] = _vn1;

        v[2] = _v2;
        vt[2] = _vt2;
        vn[2] = _vn2;
    }
};

struct vertice{
    float x, y, z;
    vertice(float _x, float _y, float _z){
        x = _x;
        y = _y;
        z = _z;
    }
};

struct normal{
    float x, y, z;
    normal(float _x, float _y, float _z){
        x = _x;
        y = _y;
        z = _z;
    }
};


struct object{
    std::vector<face> faces;
    std::vector<vertice> vertices;
    std::vector<normal> normais;
};


class ObjLoader{
private:
    
public:
    void loadModel(object &Model, const char *filePath);
    vertice getVertice(std::string s);
    normal getNormal(std::string s);
    face getFace(std::string s);

};




