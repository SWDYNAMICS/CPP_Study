#include <iostream>
using namespace std;

class Point
{
private:
    int xpos;
    int ypos;
public:
    Point (int x, int y) : xpos(x) , ypos(y)
    { }
    void ShowPosition(){
        cout << "[" << xpos << " ," << ypos << "]" << endl;
    }
    Point operator-(){
        Point pos(-xpos, -ypos);
        return pos;
    }
    friend Point operator~(const Point& ref);
};
Point operator~(const Point& ref){
    Point pos(ref.ypos, ref.xpos);
    return pos;
}

int main(){
    Point pos(11,28);
    Point posMinus = -pos;
    Point posNot = ~pos;
    pos.ShowPosition();
    posMinus.ShowPosition();
    posNot.ShowPosition();
    return 0;
}