#include <iostream>
using namespace std;

class Point
{
private:
    int xpos, ypos;
public:
    Point(int x=0, int y=0) : xpos(x) , ypos(y)
    { }
    void ShowPosition() const
    {
        cout << '[' << xpos << ", " << ypos <<']'<< endl;
    }

    /* 멤버함수 기반 오버로딩 */
    const Point operator+=(const Point &ref){
        xpos += ref.xpos;
        ypos += ref.ypos;
        /*객체 자신을 가리키는 포인터의 값을 의미 asterisk 빼면
        invalid conversion 포인터와 정수의 연산 불가*/
        return *this;
    }
    /* 멤버함수 기반 오버로딩 */
    const Point operator-=(const Point &ref){
        xpos -= ref.xpos;
        ypos -= ref.ypos;
        return *this;
    }
    /* 전역 변수 기반의 연산자 오버로딩 */
    friend Point operator-(const Point & pos1, const Point & pos2);    
    friend bool operator==(const Point & pos1, const Point & pos2);
    friend bool operator!=(const Point & pos1, const Point & pos2);
};

Point operator-(const Point & pos1, const Point & pos2){
    Point pos(pos1.xpos - pos2.xpos, pos1.ypos - pos2.ypos);
    return pos;
}
bool operator==(const Point & pos1, const Point & pos2){
    if(pos1.xpos == pos2.xpos && pos1.ypos == pos2.ypos){
        return true;
    } else {
        return false;
    }
}
bool operator!=(const Point &pos1, const Point &pos2){
    if(operator==(pos1, pos2) == true){
        return false;
    } else {
        return true;
    }
} 

int main(){
    Point pos1(10,12);
    Point pos2(2,4);
    Point pos3(3,5);
    Point pos4(13,13);
    Point pos5(13,13);
    /*멤버함수 기반 호출*/
    (pos1+=pos2).ShowPosition();
    (pos2-=pos3).ShowPosition();
    /*전역함수 기반 호출*/
    cout << (bool)operator==(pos4,pos5) << endl;
    cout << (bool)operator!=(pos4,pos5) << endl;


    return 0;
}