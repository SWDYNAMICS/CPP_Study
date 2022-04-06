#include <iostream>
#include <cstring>
using namespace std;

class Rectangle{
private:
    int width;
    int height;
public:
    Rectangle(int w, int h) :width(w) , height(h) { }
    void ShowAreaInfo(){
        cout << "Area : " << width * height << endl;
    }
};
class Square : public Rectangle{
private:
    int length;
public:
    Square(int l) : Rectangle(l, l){ }
};

int main(){
    Rectangle rec(4,3);
    rec.ShowAreaInfo();

    Square sqr(7);
    sqr.ShowAreaInfo();
    return 0;
}