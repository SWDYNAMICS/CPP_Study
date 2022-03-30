#include <iostream>
#include <cstring>
using namespace std;
class TwoNumber{
private:
    int num1, num2;
public:
    TwoNumber(int num1, int num2){
        this -> num1 = num1;
        this -> num2 = num2;
    }
    
    TwoNumber(int num1, int num2, bool ok)  
        : num1(num1), num2(num2){
        // 멤버 이니셜라이저를 사용한 위의 생성자와 같은 역할, 
        // 괄호안은 매개변수로, 저장할 변수는 멤버변수로 인식한다.
        // empty
    }
    
    void Show() const{
        cout << "num1: " << num1 << ", num2: " << num2 << endl; 
    }
};
int main(){
    TwoNumber obj(2,5 ,true);
    obj.Show();
    return 0;
}