#include <iostream>
#include <cstring>
using namespace std;
namespace COMP_POS{
    enum {CLERK, SENIOR, ASSIST, MANAGER};
    void ShowPosition(int pos){
        switch(pos){
            case CLERK:
                cout << "CLERK" << endl;
                break;
            case SENIOR:
                cout << "SENIOR" << endl;
                break;
            case ASSIST:
                cout << "ASSIST" << endl;
                break;
            case MANAGER:
                cout << "MANAGER" << endl;
                break;
        }
        cout << endl;
    }
}
class NameCard{
private:
    char *name;
    char *companyName;
    char *phoneNum;
    int pos;
public:
    NameCard(char * myname, char * myCompany, char * myPhone, int myPos):pos(myPos){
        int len1 = strlen(myname);
        int len2 = strlen(myCompany);
        int len3 = strlen(myPhone);
        name = new char[len1];
        companyName = new char[len2];
        phoneNum = new char[len3];
        strcpy(name,myname);
        strcpy(companyName,myCompany);
        strcpy(phoneNum,myPhone);
        
    }
    void ShowNameCardInfo(){
        cout << "name: " << name << endl;
        cout << "company: " << companyName << endl;
        cout << "phone: " << phoneNum << endl;
        cout << "position:" ; COMP_POS::ShowPosition(pos);
    }
    ~NameCard(){
        delete []name;
        delete []companyName;
        delete []phoneNum;
    }
};
int main(){
    NameCard manClerk = NameCard("lee", "samsung","010-1233-1230",COMP_POS::CLERK);
    NameCard manASSIST = NameCard("prk", "LG","010-1123-1231",COMP_POS::ASSIST);
    NameCard manSenior = NameCard("son", "Mobis","010-1523-1232",COMP_POS::SENIOR);
    manClerk.ShowNameCardInfo();
    manASSIST.ShowNameCardInfo();
    manSenior.ShowNameCardInfo();
    return 0;
}