#include <iostream>
#include <cstring>
using namespace std;
class SoBase{
private:
    int baseNum;
public:
    SoBase(int n) : baseNum(n){
        cout << "SoBase(void)" << baseNum<< endl;
    }
    ~SoBase(){
        cout << "~SoBase()" << baseNum <<endl;
    }
    
};
class SoDerived : public SoBase{
private:
    int deriNum;
public:
    SoDerived(int n) : SoBase(n), deriNum(n){
        cout << "derNum(void)" << deriNum << endl;
    }
    ~SoDerived(){
        cout << "~SoDerived()" << deriNum << endl;
    }
    
};
int main(){
    SoDerived drv1(15);
    SoDerived drv2(27);
    return 0;
}