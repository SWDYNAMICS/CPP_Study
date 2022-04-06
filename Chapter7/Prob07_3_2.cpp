#include <iostream>
#include <cstring>
using namespace std;
class Book{
private:
    char *title;
    char *isbn;
    int price;
public:
    Book(char *title, char *isbn, int bookPrice) : price(bookPrice){
        this -> title = new char[strlen(title) + 1];
        strcpy(this->title, title);
        this -> isbn = new char[strlen(isbn) + 1];
        strcpy(this->isbn, isbn);
    }
    void BookInfo(){
        cout << "title : " << title << endl;
        cout << "isbn : " << isbn << endl;
        cout << "price : " << price << endl;
    }
    ~Book(){
        delete [] title;
        delete [] isbn;
    }
};
class Ebook : public Book{
private:
    char *DRMkey;
public:
    Ebook(char *title, char *isbn, int bookPrice, char * DRMkey): Book(title, isbn, bookPrice) {
        this->DRMkey = new char[strlen(DRMkey) + 1];
        strcpy(this->DRMkey, DRMkey);
    }
    ~Ebook(){
        delete [] DRMkey;
    }
};
int main(){
    Book book("Good book", "123-123-123", 12000);
    book.BookInfo();
    cout << endl;
    Ebook ebook("Better book", "234-234-234", 15000, "aoi213z");
    ebook.BookInfo();
    cout << endl;
    return 0;
}