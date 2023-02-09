#include <vector>
#include <string>
struct face{
    int vertice[4];
    face(int a, int b, int c, unsigned int index){
        vertice[0] = a;
        vertice[1] = b;
        vertice[2] = c;
        vertice[3] = index;
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

struct object{
    std::vector<face> faces;
    std::vector<vertice> vertices;
};


class ObjLoader{
private:
    /* data */
public:
    void loadModel(object &Model, const char *filePath);

    /*
    vertice getVertice(std::string s);
    face getFace(std::string s);

    */
};




