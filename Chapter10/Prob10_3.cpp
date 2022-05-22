#include <iostream>
using namespace std;
class Point{
private:
    int xpos, ypos;
public:
    Point(int x = 0, int y = 0) : xpos(x), ypos(y){
        
    }
    void ShowPosition(){
        cout << '['<< xpos << ", " << ypos << ']' << endl;
    }
    friend ostream& operator<< (ostream& os, const Point& pos);
    friend istream& operator>> (istream& os, Point& pos);

};
ostream& operator<< (ostream& os, const Point& pos){
    os << "[" << pos.xpos << ", " << pos.ypos << " ]"<< endl;
    return os;
}
istream& operator>> (istream& os, Point& pos){
    os >> pos.xpos >> pos.ypos;
    return os;
}


int main(){
    Point pos1;
    cout << "input x value & y value: ";
    cin >> pos1;
    cout << pos1 << endl;
    
    Point pos2;
    cout << "input x value & y value: ";
    cin >> pos2;
    cout << pos2 << endl;
    return 0;   
}